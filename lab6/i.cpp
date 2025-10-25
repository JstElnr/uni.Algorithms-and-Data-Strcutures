#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count[26]={0};
    for(char c:s){
        count[c-'a']++;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<count[i];j++){
            cout<<char('a'+i);
        }
    }
    cout<<"\n";
    return 0;
}