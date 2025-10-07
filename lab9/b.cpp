#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,t;
    int k;
    cin>>s>>k;
    cin>>t;
    int cnt=0;
    for(size_t pos=t.find(s);pos!=string::npos;pos=t.find(s,pos+1)) cnt++;
    if(cnt>=k) cout<<"YES";
    else cout<<"NO";
    return 0;
}
