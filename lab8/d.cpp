#include <bits/stdc++.h>
using namespace std;
struct AC{
    struct Node{int nxt[26],link,out;Node(){memset(nxt,-1,sizeof nxt);link=0;out=0;}};
    vector<Node>tr;AC(){tr.assign(1,Node());}
    int add(const string&s){int v=0;for(char c:s){int x=c-'a';if(tr[v].nxt[x]==-1){tr[v].nxt[x]=tr.size();tr.push_back(Node());}v=tr[v].nxt[x];}return v;}
    void build(){
        queue<int>q;for(int c=0;c<26;c++){int u=tr[0].nxt[c];if(u==-1)tr[0].nxt[c]=0;else{tr[u].link=0;q.push(u);}}
        while(!q.empty()){int v=q.front();q.pop();for(int c=0;c<26;c++){int u=tr[v].nxt[c];if(u==-1){tr[v].nxt[c]=tr[tr[v].link].nxt[c];continue;}tr[u].link=tr[tr[v].link].nxt[c];q.push(u);}}
    }
};
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int N;while(cin>>N&&N){
        vector<string>pat(N);for(int i=0;i<N;i++)cin>>pat[i];string text;cin>>text;
        AC ac;vector<int>term(N);for(int i=0;i<N;i++)term[i]=ac.add(pat[i]);
        ac.build();vector<int>cnt(ac.tr.size());int v=0;
        for(char ch:text){v=ac.tr[v].nxt[ch-'a'];cnt[v]++;}
        vector<int>ord(ac.tr.size());iota(ord.begin(),ord.end(),0);
        stable_sort(ord.begin(),ord.end(),[&](int a,int b){return a!=b&&a&&b?0:0;});
        vector<int>bylen(ac.tr.size());for(int i=0;i<(int)ac.tr.size();i++)bylen[i]=0;
        vector<int>len(ac.tr.size()); // compute len via BFS parents
        queue<int>q;vector<int>par(ac.tr.size(),-1),pch(ac.tr.size(),-1);q.push(0);
        while(!q.empty()){int x=q.front();q.pop();for(int c=0;c<26;c++){int u=ac.tr[x].nxt[c];if(u&&par[u]==-1){par[u]=x;pch[u]=c;len[u]=len[x]+1;q.push(u);}}}
        vector<int>order(ac.tr.size());iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int a,int b){return len[a]>len[b];});
        for(int u:order)if(u)cnt[ac.tr[u].link]+=cnt[u];
        vector<int>f(N);int mx=0;for(int i=0;i<N;i++){f[i]=cnt[term[i]];mx=max(mx,f[i]);}
        cout<<mx<<"\n";for(int i=0;i<N;i++)if(f[i]==mx)cout<<pat[i]<<"\n";
    }
    return 0;
}
