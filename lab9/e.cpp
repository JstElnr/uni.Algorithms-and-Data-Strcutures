#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        long long k;
        cin>>s>>k;
        int n=s.size();
        vector<int> pi(n);
        for(int i=1;i<n;i++){
            int j=pi[i-1];
            while(j>0&&s[i]!=s[j]) j=pi[j-1];
            if(s[i]==s[j]) j++;
            pi[i]=j;
        }
        int per=n-pi[n-1];
        long long ans=(long long)per*(k-1)+n;
        cout<<ans<<"\n";
    }
    return 0;
}
