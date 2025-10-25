#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,string> originalToCurrent;
    map<string,string> newToOriginal;
    for(int i=0;i<n;i++){
        string oldNick,newNick;
        cin>>oldNick>>newNick;
        string original;
        if(newToOriginal.count(oldNick)){
            original=newToOriginal[oldNick];
        }else{
            original=oldNick;
        }
        originalToCurrent[original]=newNick;
        newToOriginal[newNick]=original;
            }
        cout<<originalToCurrent.size()<<"\n";
        for(auto it=originalToCurrent.begin(); it!=originalToCurrent.end();it++){
            cout<<it->first<<" "<<it->second<<"\n";
        }
        return 0;
    }