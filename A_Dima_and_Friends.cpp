#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int temp;
    int a = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        a += temp;
    }
    int r = (a-1) % (n+1);
    if(n+1 > 5){
        if(n+1 - r > 5){
            cout << 5 << endl;
            return 0;
        }
        cout << 4 << endl;
        return 0;
    }
    if(n+1 == 5){
        cout << 4 << endl;
    }
    else if(n+1 == 4){
         if(r == 3){
            cout << 3 << endl;
         }
         else{
            cout << 4 << endl;
         }
    }
    else if(n+1 == 3){
        if(r == 0){
            cout << 4 << endl;
        }
        else{
            cout << 3 << endl;
        }
    }
    else{
        if(r == 0){
            cout << 3 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}