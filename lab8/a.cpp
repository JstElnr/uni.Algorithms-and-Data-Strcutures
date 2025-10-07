#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long H(const string&s){
    long long h=0,pw=1;
    for(char c:s){
        h=(h+(c-47)*pw)%MOD;
        pw=pw*11%MOD;
    }
    return h;
}
bool isHashCandidate(const string&s,long long&val){
    if(s.empty())return false;
    for(char c:s)if(c<'0'||c>'9')return false;
    if(s.size()>10)return false;
    unsigned long long x=0;
    for(char c:s){
        x=x*10+(c-'0');
        if(x>1000000007ULL)return false;
    }
    val=(long long)x;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<string>a(2*n);
    for(int i=0;i<2*n;i++)cin>>a[i];
    unordered_map<long long,int>cnt;
    for(auto&s:a){
        long long v;
        if(isHashCandidate(s,v))cnt[v]++;
    }
    unordered_map<long long,int>used;
    for(auto&s:a){
        long long h=H(s);
        if(cnt.count(h)&&used[h]<cnt[h]){
            cout<<"Hash of string \""<<s<<"\" is "<<h<<"\n";
            used[h]++;
        }
    }
}
