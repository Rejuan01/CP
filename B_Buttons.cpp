#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int total = 0;
    for(int i = 1; i < n; i++){
        total += i*(n-i);
    }
    total += n;
    cout << total << endl;
    return 0;
}

// (n-1) + 2(n-2) +3(n-3) +....(n-1)(1) + n
// (n-1) steps to get the 1st button write, 2*(n-2) steps to get the second button write
// last part is not n*(n-n) rather it's n button to press finally