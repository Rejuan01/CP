#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a, b, c;
        cin >> a >> b >> c;
        if(a >= c){ // one box costs less than or equal one unit
            cout << -1 << " " << b << endl;
            continue;
        }
        if(a*b <= c){ // box costs more!!
            cout << b-1 << " " << -1 << endl;
            continue;
        }
        if(a*b > c){ // normal case
            cout << 1 << " " << b << endl;
        }
    }
}