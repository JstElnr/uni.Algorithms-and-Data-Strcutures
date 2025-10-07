#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,k;cin>>n>>k;
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    long long sum=0;
    while(n--){
        string s;long long x;cin>>s;
        if(s=="insert"){
            cin>>x;
            if(pq.size()<k){pq.push(x);sum+=x;}
            else if(x>pq.top()){sum+=x-pq.top();pq.pop();pq.push(x);}
        }else cout<<sum<<"\n";
    }
}
