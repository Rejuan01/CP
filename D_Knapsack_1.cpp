#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<ll>;
void solve(){
    ll n, x;
    cin >> n >> x;
    vi w(n+1), v(n+1);
    for(ll i = 1; i <= n; i++) cin >> w[i] >> v[i];
    vector<vi> dp(n+1, vi(x+1)); // dp[i][j] = max value can be achived from first i elements with j knapsack capacity
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j]; //not taking the i th wight
            if(w[i] <= j)
                dp[i][j] = max(dp[i][j], v[i]+dp[i-1][j-w[i]]); // consider taking the i th weight if possible
        }
    }
    cout << dp[n][x] << endl; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
