//Problem: Find the largest positive integer that divides both numbers a and b.
#include<iostream>
//#include<numeric>
using namespace std;

int gcdd(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a%=b;
        }
        else b%=a;
    }
    return a+b;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcdd(a,b)<<endl;
    //cout<<gcd(a,b);
    return 0;
}