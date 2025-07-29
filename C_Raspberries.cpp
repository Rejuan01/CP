#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int m = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> r;
        for(int i = 0; i < n; i++){
            int d = k;
            if(k == 4) d = 2;
            int tmp = (d - a[i] % d) % d; // last % to handle zero
            r.push_back(tmp);
        }
        sort(r.begin(), r.end());
        if(k==4){       
            int ans = r[0]+r[1];
            for(int it : a){
                int tmp = (k - it%k)%k;
                if(tmp < ans){
                    ans = tmp;
                }
            }
            cout << ans << endl;
        }else{
            cout << r[0] << endl;
        }
    }
}