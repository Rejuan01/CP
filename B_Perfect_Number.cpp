#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    long long int x = 10;
    int i = 0;
    while(i < k){
        x += 9; // first value is 19
        int p = 0;
        long long int q = x;
        while(q){
            p += (q%10);
            q /= 10;
        }
        if(p == 10){ 
            i++;
        }
    }
    cout << x << endl;
}