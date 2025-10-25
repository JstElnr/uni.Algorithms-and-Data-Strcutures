#include<bits/stdc++.h>
using namespace std;
bool isvow(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main(){
    int n;
    string s;
    cin>>n>>s;
string vowels,consonants;
for(char c:s){
    if(isvow(c))
    vowels+=c;
    else 
    consonants+=c;
}
sort(vowels.begin(),vowels.end());
sort(consonants.begin(),consonants.end());
cout<<vowels+consonants<<endl;
return 0;
}