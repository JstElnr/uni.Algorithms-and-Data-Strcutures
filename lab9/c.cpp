#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        cout<<-1;
        return 0;
    }
    string s=a+a;
    size_t pos=s.find(b);
    if(pos==string::npos) cout<<-1;
    else cout<<pos;
    return 0;
}
