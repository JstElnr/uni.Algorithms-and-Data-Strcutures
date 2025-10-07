#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val,count;
    Node *left,*right;
    Node(int v):val(v),count(1),left(nullptr),right(nullptr){}
};
Node* insert(Node*root,int x){
    if(!root)return new Node(x);
    if(x<root->val)root->left=insert(root->left,x);
    else if(x>root->val)root->right=insert(root->right,x);
    else root->count++;
    return root;
}
Node* getMin(Node*root){while(root->left)root=root->left;return root;}
Node* remove(Node*root,int x){
    if(!root)return nullptr;
    if(x<root->val)root->left=remove(root->left,x);
    else if(x>root->val)root->right=remove(root->right,x);
    else{
        root->count--;
        if(root->count==0){
            if(!root->left&&!root->right){delete root;return nullptr;}
            if(!root->left){Node*tmp=root->right;delete root;return tmp;}
            if(!root->right){Node*tmp=root->left;delete root;return tmp;}
            Node*tmp=getMin(root->right);
            root->val=tmp->val;
            root->count=tmp->count;
            tmp->count=1;
            root->right=remove(root->right,tmp->val);
        }
    }
    return root;
}
Node* find(Node*root,int x){if(!root)return nullptr;return x==root->val?root:(x<root->val?find(root->left,x):find(root->right,x));}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    Node*root=nullptr;
    while(q--){
        string cmd;
        int x;
        cin>>cmd>>x;
        if(cmd=="insert")root=insert(root,x);
        else if(cmd=="delete")root=remove(root,x);
        else if(cmd=="cnt"){Node*node=find(root,x);cout<<(node?node->count:0)<<"\n";}
    }
}
