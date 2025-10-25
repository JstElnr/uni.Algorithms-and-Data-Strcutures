#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    char target;
    cin>>target;
    auto it=upper_bound(arr.begin(),arr.end(),target);
    if(it==arr.end()){
        cout<<arr[0]<<"\n";
    }else{
        cout<<*it<<"\n";
    }
    return 0;
}