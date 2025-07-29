#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        if((a+b)%3 != 0){
            cout << "NO" << endl;
            continue;
        }
        if(a > 2*b || b > 2*a){
            cout << "NO" << endl;
            continue;
        }
        // if(a == 2*b || b == 2*a){
            // cout << "YES" << endl;
            // continue;
        // }
        else{
            cout << "YES" << endl;
        }
        // while(a > 0 && b > 0){
            // if(a < b){
                // a --;
                // b -= 2;
            // }
            // else{
                // a -= 2;
                // b --;
            // }
        // }
        // if(a == 0 && b == 0){
            // cout << "YES" << endl;
        // }
        // else{
            // cout << "NO" << endl;
        // }
    }
}