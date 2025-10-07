#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;long long k;
    cin>>n>>k;
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    for(int i=0;i<n;++i){long long x;cin>>x;pq.push(x);}
    int ans=0;
    while(pq.size()>1 && pq.top()<k){
        long long a=pq.top();pq.pop();
        long long b=pq.top();pq.pop();
        pq.push(a+2*b);
        ans++;
    }
    if(pq.top()<k)cout<<"-1\n";
    else cout<<ans<<"\n";
}
