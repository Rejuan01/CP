#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int total = 0;
        for(int i = n-1; i >= 0; i--){
            if(total+a[i] <= k){
                total += a[i];
            }
            else{
                break;
            }
        }
        k -= total;
        cout << k << endl;
    }
}