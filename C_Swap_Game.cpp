#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        cin >> a[0];
        int min = a[0];
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i] < min){
                min = a[i];
            }
        }
        if(a[0] == min){
            cout << "Bob"<< endl;
        }
        else{
            cout << "Alice" << endl;
        }
    }
}