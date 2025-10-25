#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    map<int,int> countA, countB;
    for(int x:a) countA[x]++;
    for(int x:b) countB[x]++;
    for(map<int,int>::iterator it=countA.begin(); it!=countA.end();it++){
        int num=it->first;
        int cntA=it->second;
        if(countB.count(num)){
            int times=min(cntA,countB[num]);
            for(int i=0; i<times;i++)
            cout<<num<<" ";
        }
    }
    cout<<endl;
    return 0;
}