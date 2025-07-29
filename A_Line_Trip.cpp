#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n+1);
        a[0] = 0;
        for(int i = 1; i < n+1; i++){
            cin >> a[i];
        }
        int max = 2*(x-a[n]);
        for(int i = 0; i < n; i++){
            if(a[i+1]-a[i] > max){
                max = a[i+1]-a[i];
            }
        }
        cout << max << endl;
    }
}