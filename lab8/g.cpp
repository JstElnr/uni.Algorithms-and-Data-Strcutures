#include <bits/stdc++.h>
using namespace std;
struct SAM{
    struct S{int next[26],link,len;int occ;S(){memset(next,-1,sizeof next);link=-1;len=0;occ=0;}};vector<S>st;int last;
    SAM(int n=0){st.reserve(2*n+5);st.push_back(S());last=0;}
    void add(int c){
        int cur=st.size();st.push_back(S());st[cur].len=st[last].len+1;st[cur].occ=1;
        int p=last;for(;p!=-1&&st[p].next[c]==-1;p=st[p].link)st[p].next[c]=cur;
        if(p==-1)st[cur].link=0;else{int q=st[p].next[c];if(st[p].len+1==st[q].len)st[cur].link=q;else{int clone=st.size();st.push_back(st[q]);st[clone].len=st[p].len+1;st[clone].occ=0;
            for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=clone;st[q].link=st[cur].link=clone;} }last=cur;
    }
    void build_occ(){vector<int>ord(st.size());iota(ord.begin(),ord.end(),0);sort(ord.begin(),ord.end(),[&](int a,int b){return st[a].len>st[b].len;});for(int v:ord)if(st[v].link!=-1)st[st[v].link].occ+=st[v].occ;}
    int count_sub(const string&s,int l,int r){
        int v=0,cur=0;for(int i=l;i<=r;i++){int c=s[i]-'a';while(v&&!~st[v].next[c]){v=st[v].link;cur=st[v].len;}if(~st[v].next[c]){v=st[v].next[c];cur++;}else return 0;}
        return st[v].occ;
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string S;int q;if(!(cin>>S))return 0;SAM sam(S.size());for(char c:S)sam.add(c-'a');sam.build_occ();
    cin>>q;while(q--){int L,R;cin>>L>>R;--L;--R;cout<<sam.count_sub(S,L,R)<<"\n";}
    return 0;
}
