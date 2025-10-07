#include <bits/stdc++.h>
using namespace std;
vector<int>kmp(const string&t){
    int n=t.size();
    vector<int>p(n);
    for(int i=1;i<n;i++){int j=p[i-1];
        while(j&&t[i]!=t[j])j=p[j-1];
        if(t[i]==t[j])j++;
        p[i]=j;
    }return p;
}
vector<int>occ(const string&s,const string&t){
    string u=t+"#"+s;
    auto p=kmp(u);
    int m=t.size();
    vector<int>res(s.size());
    for(int i=m+1;i<(int)u.size();i++)if(p[i]==m)res[i-2*m]=1;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2,t;
    if(!(cin>>s1>>s2>>t))return 0;
    auto a=occ(s1,t),b=occ(s2,t);
    int m=t.size(),n=s1.size(),ans=0;
    for(int i=0;i+m<=n;i++)if(a[i]&&i+m<=((int)s2.size())&&b[i])ans++;
    cout<<ans<<"\n";
    return 0;
}
