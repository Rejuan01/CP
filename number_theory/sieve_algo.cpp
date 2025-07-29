#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool> isPrime(n, 1);     //set all as prime
    isPrime[0] = isPrime[1] = false;//set 0, 1 as non prime
    for(int i = 2; i < n/2; i++){   // better to use i*i < n
        if(isPrime[i]){
            for(int j = i*i; j < n; j += i){ // j = 2i, 3i, 4i ...
                isPrime[j] = false;         // set multiple of a prime as non prime
            }
        }
    }
    for(int i = 2; i < n; i++){
        if(isPrime[i]){
            cout << i << " ";
        }
    }
    cout << endl;
    //cout << "__dsjc : " << isPrime[162] << endl;
}

// time complexity almost nlog(log(n))