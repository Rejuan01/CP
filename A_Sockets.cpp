#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(m <= k){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < n; i++){
        k--; // one socket is used by a filter
        k += a[i]; // a[i] socket added by a filter
        if(k >= m){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}