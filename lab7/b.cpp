#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> leftpart(arr.begin()+left,arr.begin()+mid+1);
    vector<int> rightpart(arr.begin()+mid+1,arr.begin()+right+1);

    int i=0,j=0,k=left;

    while(i<leftpart.size()&&j<rightpart.size()){
        if(leftpart[i]<=rightpart[j]){
            arr[k++]=leftpart[i++];
        }else arr[k++]=rightpart[j++];
    }

    while(i<leftpart.size()) arr[k++]=leftpart[i++];
    while(j<rightpart.size()) arr[k++]=rightpart[j++];
}

void mergesort(vector<int>& arr,int left, int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main(){
    int n,m;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin>>b[i];

    vector<int> arr=v;
    arr.insert(arr.end(),b.begin(),b.end());

    merge(arr,0,n-1,n+m-1);

    for(int i=0;i<arr.size();i++){
        if(i) cout<<' ';
        cout<<arr[i];
    }
    cout<<endl;
}