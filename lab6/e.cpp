#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>mat[i][j];
    for(int j=0;j<m;j++){
        vector<int> col(n);
        for(int i=0;i<n;i++)
        col[i]=mat[i][j];
        sort(col.begin(),col.end(),greater<int>());
        for(int i=0;i<n;i++)
        mat[i][j]=col[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}