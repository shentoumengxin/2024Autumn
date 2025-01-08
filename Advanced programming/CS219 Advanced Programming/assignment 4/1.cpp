#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

using namespace std;

class Card {
public:
    string name;
    int value;

    Card(const string& name, int value) : name(name), value(value) {}

    virtual void use(class Player& user, class Player& target) = 0;

    virtual ~Card() = default;
};

class AttackCard : public Card {
public:
    AttackCard(const string& name, int value) : Card(name, value) {}

    void use(Player& user, Player& target) override;
};

class HealCard : public Card {
public:
    HealCard(const string& name, int value) : Card(name, value) {}

    void use(Player& user, Player& target) override;
};

class StunCard : public Card {
public:
    StunCard(const string& name, int value) : Card(name, value) {}

    void use(Player& user, Player& target) override;
};

class ShieldCard : public Card {
public:
    ShieldCard(const string& name, int value) : Card(name, value) {}

    void use(Player& user, Player& target) override;
};

class Player {
public:
    string name;
    int hp;
    int initialHp;
    bool shieldActive = false;
    bool stunned = false;

    Player(const string& name, int initialHp) : name(name), hp(initialHp), initialHp(initialHp) {}

    void takeDamage(int damage) {
        
        if(shieldActive){
            shieldActive=false;
            return;
        }else{
            hp -= damage;
           // if (hp < 0) hp = 0;
        }
    }

    void heal(int amount) {
        // TODO
        hp+=amount;
        if(hp>initialHp)hp=initialHp;
    }

    void activateShield() {
        // TODO
        shieldActive = true;
    }

    void applyStun() {
        // TODO
        stunned=true;
    }

    void resetTurnStatus() {
    stunned = false;


    }

    bool isDefeated() const {
        // TODO
        return hp <= 0;
    }
};
void AttackCard::use(Player& user, Player& target) {
    target.takeDamage(this->value);
}

void HealCard::use(Player& user, Player& target) {
    target.heal(this->value);
}

void StunCard::use(Player& user, Player& target) {
    target.applyStun();
}

void ShieldCard::use(Player& user, Player& target) {
    target.activateShield();
}


class Game {
private:
    Player playerA, playerB;
    unordered_map<int, shared_ptr<Card> > cardLibrary;

public:
    Game(const string& playerAName, int hpA, const string& playerBName, int hpB) 
        : playerA(playerAName, hpA), playerB(playerBName, hpB) {}

    void addCardToLibrary(int cardId, const string& name, int value) {
        if (name == "HXB") {
            cardLibrary[cardId] = make_shared<AttackCard>(name, value);
        }
        else if (name == "SH") {
            cardLibrary[cardId] = make_shared<HealCard>(name, value);
        }
        else if (name == "TFE") {
            cardLibrary[cardId] = make_shared<StunCard>(name, value);
        }
        else if (name == "AS") {
            cardLibrary[cardId] = make_shared<ShieldCard>(name, value);
        }
    }

    void playTurn(Player& currentPlayer, Player& opponent, int cardId, Player& target) {
    if (currentPlayer.stunned) {
        currentPlayer.resetTurnStatus();
        return;
    }

    auto it = cardLibrary.find(cardId);
    if (it != cardLibrary.end()) {
        it->second->use(currentPlayer, target);
    }
    else {
        return;
    }

    
    if (target.isDefeated()) {
        this->displayWinner(currentPlayer);
        exit(0);
    }
}



    void displayPlayerStatus() {
        
        cout << playerA.name << " " << playerA.hp;
        if (playerA.shieldActive) {
            cout << " (Shield Active)";
        }
        if (playerA.stunned) {
            cout << " (Stunned)";
        }
        cout << endl;

        cout << playerB.name << " " << playerB.hp;
        if (playerB.shieldActive) {
            cout << " (Shield Active)";
        }
        if (playerB.stunned) {
            cout << " (Stunned)";
        }
        cout << endl;
    }

    void displayWinner(Player& winner) {
        cout << winner.name << " wins!" << endl;
    }

    void processAction(const string &currentPlayerName, int cardId, const string &targetPlayerName) {  
        Player& currentPlayer = (currentPlayerName == playerA.name) ? playerA : playerB;
        Player& opponent = (currentPlayerName == playerA.name) ? playerB : playerA;
        Player& target = (targetPlayerName == playerA.name) ? playerA : playerB;

        playTurn(currentPlayer, opponent, cardId, target);

        // 判断是否有玩家HP为0，若是，则判定另一位玩家获胜
        if (playerA.isDefeated()) {
            this->displayWinner(playerB);  // Player B wins
            exit(0);
        } 
        else if (playerB.isDefeated()) {
            this->displayWinner(playerA);  // Player A wins
            exit(0);
        }
    }
};



int main() {
string playerAName, playerBName;
    int hpA, hpB;
    cin >> playerAName >> hpA;
    cin >> playerBName >> hpB;
    if(hpA<=0){
        cout<<playerAName<<" wins!"<<endl;
        return 0;
    }
    if(hpB<=0){
        cout<<playerBName<<" wins!"<<endl;
        return 0;
    }
    Game game(playerAName, hpA, playerBName, hpB);

    for(int i = 0; i < 4; ++i) {
        int cardId, value;
        string cardName;
        cin >> cardId >> cardName >> value;
        game.addCardToLibrary(cardId, cardName, value);
    }

    string actionPlayer, targetPlayer;
    int cardId;
    while(cin >> actionPlayer >> cardId >> targetPlayer) {
        game.processAction(actionPlayer, cardId, targetPlayer);
    }


    game.displayPlayerStatus();

    return 0;
}