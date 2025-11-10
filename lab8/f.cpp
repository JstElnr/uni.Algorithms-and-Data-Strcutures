#include <bits/stdc++.h>
using namespace std;
struct SAM{
    struct S{
int next[26],link,len;
long long occ;
S(){
    memset(next,-1,sizeof next);
    link=-1;
    len=0;
    occ=0;
}
};
vector<S>st;
int last;
    SAM(int n=0){
        st.reserve(2*n+5);
        st.push_back(S());
        last=0;
    }
    void add(int c){
        int cur=st.size();
        st.push_back(S());
        st[cur].len=st[last].len+1;
        st[cur].occ=1;
        int p=last;
        for(;p!=-1&&st[p].next[c]==-1;
            p=st[p].link)st[p].next[c]=cur;
        if(p==-1)st[cur].link=0;
        else{int q=st[p].next[c];
             if(st[p].len+1==st[q].len)st[cur].link=q;
             else{int clone=st.size();
                  st.push_back(st[q]);
                  st[clone].len=st[p].len+1;
                  st[clone].occ=0;
            for(;p!=-1&&st[p].next[c]==q;
                p=st[p].link)st[p].next[c]=clone;
                  st[q].link=st[cur].link=clone;}
        }last=cur;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin>>s))return 0;
    SAM sam(s.size());
    for(char c:s)sam.add(c-'a');
    vector<int>ord(sam.st.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int a,int b){
        return sam.st[a].len>sam.st[b].len;});
    for(int v:ord)if(sam.st[v].link!=-1)sam.st[sam.st[v].link].occ+=sam.st[v].occ;
    long long ans=0;
    for(size_t i=1;i<sam.st.size();i++)ans+=sam.st[i].len-sam.st[sam.st[i].link].len;
    cout<<ans<<"\n";return 0;
}

