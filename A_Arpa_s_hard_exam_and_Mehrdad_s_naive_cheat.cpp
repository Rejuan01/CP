#include<bits/stdc++.h>
using namespace std;


int main(){
    long  int n; 
    cin >> n;
    int x = 1378;
    int result = 1;
    while(n){
        if(n % 2 == 1){
            result = (result * x) % 10;
            n--;
        }
        else{
            x = (x*x) % 10;
            n /= 2;
        }
    }
    cout << result << endl;
}