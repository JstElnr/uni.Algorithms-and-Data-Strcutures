#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N))return 0;
    vector<unsigned long long>p(N),pow2(N+1,1);
    for(int i=1;i<=N;i++)pow2[i]=pow2[i-1]<<1;
    for(int i=0;i<N;i++)cin>>p[i];
    string s;
    for(int i=0;i<N;i++){
        unsigned long long diff=p[i]-(i?p[i-1]:0ULL);
        unsigned long long v=diff>>i;
        char c=(char)(v+97);
        s.push_back(c);
    }
    cout<<s<<"\n";
    return 0;
}

