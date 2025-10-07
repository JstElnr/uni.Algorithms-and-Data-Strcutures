#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    string s=a;
    int ans=1;
    while(s.size()<b.size()){
        s+=a;
        ans++;
    }
    if(s.find(b)!=string::npos){
        cout<<ans;
        return 0;
    }
    s+=a;
    ans++;
    if(s.find(b)!=string::npos) cout<<ans;
    else cout<<-1;
    return 0;
}
