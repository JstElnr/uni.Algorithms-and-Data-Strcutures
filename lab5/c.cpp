#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    priority_queue<long long>pq;
    for(int i=0;i<n;++i){long long x;cin>>x;pq.push(x);}
    long long ans=0;
    while(m--){
        long long k=pq.top();pq.pop();
        ans+=k;
        if(k>1)pq.push(k-1);
    }
    cout<<ans<<"\n";
}
