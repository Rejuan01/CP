#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a;
    cin >> n >> a;
    int t[n];
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int count = 0;
    int p = 1;
    a--; // to use a as index
    if(t[a]){
        count++;
    }
    while(a-p >= 0 && a+p < n){
        if(t[a-p] && t[a+p]){
            count += 2;
        }
        p++;
    }
    if(n % 2 == 1 && a == n/2){
        cout << count << endl;
        return 0;
    }

    while(a-p >= 0){
        if(t[a-p]){
            count++;
        }
        p++;
    }
    while(a+p < n){
        if(t[a+p]){
            count++;
        }
        p++;
    }
    cout << count << endl;
}