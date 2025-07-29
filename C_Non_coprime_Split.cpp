#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        if(r < 4){
            cout << -1 << endl;
            continue;
        }else if(l < 4){
            cout << 2 << " " << 2 << endl;
            continue;
        }
        int x = 2;
        int y = l-2;
        if(y%2 == 0){
            cout << x << " " << y << endl;
            continue;
        }
        else if(x+y+1 <= r){
            cout << x << " " << y+1 << endl;
            continue;
        }// else l == r & both odd
        bool flag = true;
        for(int k = 3; k*k <= r && flag; k+=2){
            if(r%k == 0){
                cout << k << " " << r-k << endl;
                flag = false;
            }
        }
        if(flag){
            cout << -1 << endl;
        }
    }
}