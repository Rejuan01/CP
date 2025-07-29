#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> prime_factors;
    for(int i = 2; i*i <= n; i++){  //for composite number atleast one prime factor exists before sqrt(n)
        while(n % i == 0){          //if divisible by a prime factor, divide by it till possible
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1){  //if n is not composite(a prime number) no factor will be founded before sqrt(n)
        prime_factors.push_back(n);         // example: 24 = 2*2*2*3; n=24 -> 12 -> 6 -> 3 (not composite)
    }

    for(int i: prime_factors){
        cout << i << " ";
    }
}