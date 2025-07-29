#include<bits/stdc++.h>
using namespace std;
// bool isPrime(int n) {
//     //if (n <= 1) return false;         
//     if (n <= 3) return true;          
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0) return false;
//     }
//     return true;
// }
int lowest_divisor(int n) {
    if (n % 2 == 0) return 2;  
    if (n % 3 == 0) return 3;  

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return i;
        if (n % (i + 2) == 0) return i + 2;
    }
    return n;  // then n is prime
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // if(n%2 == 0){
        //     cout << n/2 << " " << n/2 << endl;
        //     continue;
        // }else if(isPrime(n)){
        //     cout << 1 << " " << n-1 << endl;
        //     continue;
        // }
        int x = lowest_divisor(n); // General case
        cout << n/x << " " << (n/x)*(x-1) << endl;
    }
}