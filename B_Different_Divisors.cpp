#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<bool> isPrime(N, 1);
int main(){
    isPrime[0] = isPrime[1] = false;//set 0, 1 as non prime
    for(int i = 2; i*i < N; i++){
        if(isPrime[i]){
            for(int j = i*i; j < N; j += i){ // j = 2i, 3i, 4i ...
                isPrime[j] = false;         // set multiple of a prime as non prime
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int x = d;
        d++;        // (d+1)
        while(!isPrime[d]){
            d++;
        }
        x = d+x;    
        while(!isPrime[x]){
            x++;
        }
        //cout << d << " " << x << endl;
        cout << d*x << endl;
    }
}