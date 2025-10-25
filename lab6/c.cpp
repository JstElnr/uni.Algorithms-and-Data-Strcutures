#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> points(n);
    for(int &x:points) cin>>x;
    sort(points.begin(),points.end());
    int mindiff=INT_MAX;
    for(int i=1;i<n;i++){
        mindiff=min(mindiff,points[i]-points[i-1]);
    }
    for(int i=1;i<n;i++){
        if(points[i]-points[i-1]==mindiff){
            cout<<points[i-1]<<" "<<points[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}