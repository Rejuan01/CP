#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        int c = 1;
        while(n/4){
            c *= 2;
            n /= 4;
        }
        cout << c << endl;

    }
}