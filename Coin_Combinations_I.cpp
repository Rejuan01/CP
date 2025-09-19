#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7; // Gets TLE in CSES without this const !!!!!!!!!!!!!!!
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), dp(x+1); // dp[i] = no of ways to get i amount of money
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(auto &it: a){
            if(i-it < 0) break;
            dp[i] = (dp[i]+dp[i-it])%mod; // sum of all ways to reach i
        }
    }
    cout << dp[x] << endl;
    return 0;
}