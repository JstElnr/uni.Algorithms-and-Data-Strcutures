#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(nullptr),right(nullptr){}
};
Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val<root->val) root->left=insert(root->left, val);
    else if(val > root->val) root->right = insert(root->right, val);
    return root;
}
int diameter(Node* node, int &res){
    if(!node) return 0;
    int lh=diameter(node->left, res);
    int rh=diameter(node->right, res);
    res=max(res,lh+rh+1);
    return max(lh,rh)+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    Node* root=nullptr;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        root=insert(root,x);
    }
    int res=0;
    diameter(root,res);
    cout<<res<<"\n";
}
