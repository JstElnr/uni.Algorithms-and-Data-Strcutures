#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<int> pi(n);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s1[i]!=s1[j]) j=pi[j-1];
        if(s1[i]==s1[j]) j++;
        pi[i]=j;
    }
    vector<int> res;
    int j=0;
    for(int i=0;i<m;i++){
        while(j>0&&s2[i]!=s1[j]) j=pi[j-1];
        if(s2[i]==s1[j]) j++;
        if(j==n){
            res.push_back(i-n+2);
            j=pi[j-1];
        }
    }
    cout<<res.size()<<"\n";
    for(int x:res) cout<<x<<" ";
    return 0;
}
