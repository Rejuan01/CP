#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n < 4 || n % 2 == 1){
            cout << n << endl;
            continue;
        }
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(a[i] != a[(i+2)%n]){ // mod only affects n-2, n-1 to be compared with 0, 1
                flag = true;
                continue;
            }
        }
        if(flag){
            cout << n << endl;
            continue;
        }
        cout << n/2 + 1 << endl;
    }
}