/*Prime Numbers - Sieve of Eratosthenes
Problem: Find all prime numbers up to n efficiently.
*/

//Basic
#include<iostream>
using namespace std;

void primeFactorization(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            cout<<i<<' ';
            n/=i;
        }
    }
    if(n>1) cout<<n<<endl;
}

int main(){
    int num;
    cin>>num;
    cout<<"Prime factors: "<<primeFactorization(num);
    return 0;
}