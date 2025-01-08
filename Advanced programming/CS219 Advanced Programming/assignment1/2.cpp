#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_WORDS = 1000;
    const int MAX_LEN = 31;

    char words[MAX_WORDS][MAX_LEN];
    int counts[MAX_WORDS] = {0};
    int wordCnt = 0;
    string word;
    size_t start = 0, end;
    
    string input;
    getline(cin, input);
    
   
    while ((end = input.find(',', start)) != string::npos) {
        word = input.substr(start, end - start);
        bool found = false;
        
        for (int i = 0; i < wordCnt; ++i) {
            if (strcmp(words[i], word.c_str()) == 0) {
                counts[i]++;
                found = true;
                break;
            }
        }
        
        if (!found && wordCnt < MAX_WORDS) {
            strncpy(words[wordCnt], word.c_str(), MAX_LEN - 1);
            words[wordCnt][MAX_LEN - 1] = '\0';
            counts[wordCnt] = 1;
            wordCnt++;
        }
        
        start = end + 1;
    }
    
    word = input.substr(start);
    bool found = false;
    
    for (int i = 0; i < wordCnt; ++i) {
        if (strcmp(words[i], word.c_str()) == 0) {
            counts[i]++;
            found = true;
            break;
        }
    }
    
    if (!found && wordCnt < MAX_WORDS) {
        strncpy(words[wordCnt], word.c_str(), MAX_LEN - 1);
        words[wordCnt][MAX_LEN - 1] = '\0';
        counts[wordCnt] = 1;
        wordCnt++;
    }
    
    for (int i = 0; i < wordCnt - 1; ++i) {
        for (int j = i + 1; j < wordCnt; ++j) {
            if (strcmp(words[i], words[j]) > 0) {
                char tempWord[MAX_LEN];
                strncpy(tempWord, words[i], MAX_LEN);
                strncpy(words[i], words[j], MAX_LEN);
                strncpy(words[j], tempWord, MAX_LEN);
                
                int temp = counts[i];
                counts[i] = counts[j];
                counts[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < wordCnt; ++i) {
        cout << words[i] << ": " << counts[i] << endl;
    }
    
    return 0;
}
