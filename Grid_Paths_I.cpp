#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
ll mod = 1e9+7;
void solve(){
    ll n;
    cin >> n;
    vector<vi> dp(n, vi(n, 0));
    vector<string> s(n);
    for(ll i = 0; i < n; i++) cin >> s[i];
    if(s[0][0] != '*') dp[0][0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(s[i][j] == '*') continue;
            if(i > 0) dp[i][j] += dp[i-1][j];
            if(j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1] << endl;
    
}
// dp[i][j] = number of ways to reach (i, j) form (0, 0)
// dp[i][j] = dp[i-1][j] + dp[i][j+1]
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}