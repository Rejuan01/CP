#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int x = lcm(a, b);
        if(x == b){
            if(a == 1){
                x *= x; 
            }     
            else{
                x *= (x/a);
            }
        }
        cout << x << endl;
    }
}