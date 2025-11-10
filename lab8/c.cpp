#include <bits/stdc++.h>
using namespace std;
vector<int>kmp(const string&t){
    int n=t.size();
    vector<int>p(n);
    for(int i=1;i<n;i++){
        int j=p[i-1];
        while(j&&t[i]!=t[j])j=p[j-1];
        if(t[i]==t[j])j++;
        p[i]=j;
    }return p;
}
vector<int>matchpos(const string&s,const string&t){
    auto p=kmp(t);
    vector<int>pos;
    int n=s.size(),m=t.size(),j=0;
    for(int i=0;i<n;i++){
        while(j&&s[i]!=t[j])j=p[j-1];
        if(s[i]==t[j])j++;
        if(j==m){
            pos.push_back(i-m+1);
            j=p[j-1];
        }
    }return pos;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    if(!(cin>>s))return 0;
    cin>>n;
    vector<string>t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    int L=s.size();
    vector<int>diff(L+1);
    for(auto&x:t){
        auto v=matchpos(s,x);
        int m=x.size();
        for(int p:v){
            diff[p]++;
            diff[min(L,p+m)]--;
        }
    }
    int cur=0;
    for(int i=0;i<L;i++){
        cur+=diff[i];
        if(cur<=0){
            cout<<"NO\n";
            return 0;}
    }
    cout<<"YES\n";
    return 0;
}

