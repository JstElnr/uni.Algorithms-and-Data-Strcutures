#include <bits/stdc++.h>
using namespace std;
struct SAM{
    struct S{int next[26],link,len;int id;S(){memset(next,-1,sizeof next);link=-1;len=0;id=0;}};vector<S>st;int last;
    SAM(int n=0){st.reserve(2*n+5);st.push_back(S());last=0;}
    void add(int c){
        int cur=st.size();st.push_back(S());st[cur].len=st[last].len+1;
        int p=last;for(;p!=-1&&st[p].next[c]==-1;p=st[p].link)st[p].next[c]=cur;
        if(p==-1)st[cur].link=0;else{int q=st[p].next[c];if(st[p].len+1==st[q].len)st[cur].link=q;else{int clone=st.size();st.push_back(st[q]);st[clone].len=st[p].len+1;
            for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=clone;st[q].link=st[cur].link=clone;} }last=cur;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int K;if(!(cin>>K))return 0;vector<string>s(K);for(int i=0;i<K;i++)cin>>s[i];
    SAM sam(s[0].size());for(char c:s[0])sam.add(c-'a');
    int SZ=sam.st.size();vector<int>best(SZ,1e9),tmp(SZ),ord(SZ);iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int a,int b){return sam.st[a].len>sam.st[b].len;});
    for(int i=0;i<SZ;i++)best[i]=sam.st[i].len;
    for(int k=1;k<K;k++){
        fill(tmp.begin(),tmp.end(),0);int v=0,l=0;
        for(char ch:s[k]){
            int c=ch-'a';
            while(v&&!~sam.st[v].next[c]){v=sam.st[v].link;l=sam.st[v].len;}
            if(~sam.st[v].next[c]){v=sam.st[v].next[c];l++;}else{v=0;l=0;}
            tmp[v]=max(tmp[v],l);
        }
        for(int v:ord){int p=sam.st[v].link;if(p!=-1)tmp[p]=max(tmp[p],min(tmp[v],sam.st[p].len));}
        for(int i=0;i<SZ;i++)best[i]=min(best[i],tmp[i]);
    }
    int ans=0,pos=0;for(int i=0;i<SZ;i++)if(best[i]>ans){ans=best[i];pos=i;}
    string res;int need=ans;int v=pos;
    // backtrack by walking down from root using best-values (construct any example)
    // fallback: find any path of length 'ans' by re-walking s[0]
    if(ans==0){cout<<"\n";return 0;}
    int cur=0;v=0;
    for(char ch:s[0]){
        int c=ch-'a';
        while(v&&!~sam.st[v].next[c]){v=sam.st[v].link;cur=sam.st[v].len;}
        if(~sam.st[v].next[c]){v=sam.st[v].next[c];cur++;}else{v=0;cur=0;}
        if(best[v]>=need){res.push_back(ch);if((int)res.size()==ans)break;}
    }
    cout<<res<<"\n";return 0;
}
