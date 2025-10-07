#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=1;i<n-1;i++){
        string a=s.substr(0,i);
        string b=s.substr(i,n-i);
        if(a.size()>=b.size()) continue;
        int m=a.size();
        if(b.substr(0,m)==a&&s.substr(i)==b) ans++;
    }
    cout<<ans;
    return 0;
}
