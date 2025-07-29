#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long int a[n];
        long int max = 1;
        for(int i = 0; i < n-1; i++){
            cin >> a[i];
            
            if(a[i] > max){
                max = a[i];
            }
        }
        cin >> a[n-1];
        int total = max + a[n-1];
        cout << total << endl;
    }
}