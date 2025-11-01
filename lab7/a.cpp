#include<bits/stdc++.h>
using namespace std;

void merge(vector<string>& arr, int left, int mid, int right){
    vector<string> leftpart(arr.begin()+left,arr.begin()+mid+1);
    vector<string> rightpart(arr.begin()+mid+1,arr.begin()+right+1);

    int i=0,j=0,k=left;

    while(i<leftpart.size()&&j<rightpart.size()){
        if(leftpart[i].size()<=rightpart[j].size()){
            arr[k++]=leftpart[i++];
        }else arr[k++]=rightpart[j++];
    }

    while(i<leftpart.size()) arr[k++]=leftpart[i++];
    while(j<rightpart.size()) arr[k++]=rightpart[j++];
}

void mergesort(vector<string>& arr,int left, int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main(){
    int T;
    cin>>T;
    cin.ignore();

    while(T--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        vector<string> words;
        string w;

        while(ss>>w) words.push_back(w);

        mergesort(words,0,(int)words.size()-1);

        for(int i=0;i<(int)words.size();i++){
            if(i) cout<<' ';
            cout<<words[i];
        }
        cout<<endl;
    }
}