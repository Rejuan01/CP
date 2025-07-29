#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%4 == 0){
            int x = n/4;
            int y = sqrt(x);
            if(y*y == x){
                cout << "YES" << endl;
                continue;
            }
        }
        if(n%2 == 0){
            int x = n/2;
            int y = sqrt(x);
            if(y*y == x){
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
}