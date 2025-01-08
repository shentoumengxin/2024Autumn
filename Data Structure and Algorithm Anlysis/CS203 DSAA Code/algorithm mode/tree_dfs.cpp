#include<iostream>
#include<vector>
using namespace std;
struct node{
    node* left;
    node* right;
    int val;
};
void dfs(node* root){
    if(root==nullptr){
        return;
    }
    dfs(root->left);
    dfs(root->right);
    cout<<root->val<<endl;  //后序遍历
    // dfs(root->left);
    //  cout<<root->val<<endl;  //中序遍历
    // dfs(root->right);
   
}
void dfs(node* root){
    if(root==nullptr){
        return;
    }
    for(int i=0;i<root->sons.size();i++){
        dfs(root->sons[i]);
        cout<<root->val<<endl;  
    }
}

int main(){
    return 0;
}