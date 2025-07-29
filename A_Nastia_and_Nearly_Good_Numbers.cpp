#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a, b;
        cin >> a >> b;
        if(b == 1){
            cout << "NO" << endl;
            continue;
        }
        if(b == 2){
            cout << "YES" << endl;
            cout << a << " " << 2*a*b-a << " " << 2*a*b << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << a << " " << a*b-a << " " << a*b << endl;
    }
    return 0;
}