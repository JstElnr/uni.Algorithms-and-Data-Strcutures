#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string p;
    int n;
    cin>>p>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int best=0;
    for(int len=1;len<=p.size();len++){
        string suf=p.substr(p.size()-len);
        bool ok=false;
        for(int i=0;i<n;i++) if(v[i].substr(0,len)==suf) ok=true;
        if(ok) best=len;
    }
    vector<string> ans;
    string suf=p.substr(p.size()-best);
    for(int i=0;i<n;i++) if(v[i].substr(0,best)==suf) ans.push_back(v[i]);
    cout<<ans.size()<<"\n";
    for(string x:ans) cout<<x<<"\n";
    return 0;
}
