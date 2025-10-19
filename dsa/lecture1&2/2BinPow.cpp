#include<bits/stdc++.h>
//RECURSIVE
long long binpow(long long a, long long n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        long long half=binpow(a,n/2);
        return half*half;
    }
    else{
        return a*binpow(a,n-1);
    }
}
//ITERATIVE
long long binpow_iter(long long a, long long n){
    long long result=1;
    while(n>0){
        if(n%2==1){
            result*=a;
        }
        a*=a;
        n/=2;
    }
    return result;
}

int main(){
    long long base,exp;
    cin>>base>>exp;
    cout<<"res: "<<binpow(base,exp)<<endl;
    cout<<"res (iterative): "<<binpow_iter(base,exp);
    return 0;
}