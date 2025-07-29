#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < n-i; j++){
            cout << "  ";
        }
        for(int j = 0; j <= i; j++){
            cout << j;
            if(i){
                cout << " ";  // should not contain unnecessary trailing space "0 " at the very first line
            }
        }
        for(int j = i-1; j >=0; j--){
            cout << j ;
            if(j){
                cout << " "; // should not contain unnecessary trailing space "0 "
            }
        }
        cout << endl;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n-i; j++){
            cout << "  ";
        }
        for(int j = 0; j <= i; j++){
            cout << j ;
            if(i){
                cout << " ";   // for last "0", this should not be "0 "
            }
        }
        for(int j = i-1; j >=0; j--){
            cout << j;
            if(j){
                cout << " ";
            }
        }
        cout << endl;
    }
}