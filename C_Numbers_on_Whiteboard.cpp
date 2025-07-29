#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << 2 << endl;
        if(n == 2){
            cout << 1 << " " << 2 << endl;
            continue;
        }

        cout << n-2 << " " << n << endl;
        cout << n-1 << " " << n-1 << endl;
        int x = n-3, y = n-1;

        if(n > 3){
            while(x){
                cout << y-- << " " << x-- << endl;
            }
        }
    }

}