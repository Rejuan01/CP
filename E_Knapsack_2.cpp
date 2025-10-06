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
void solve(){
    ll n, x;
    cin >> n >> x;
    vi w(n+1), v(n+1);
    for(ll i = 1; i <= n; i++) cin >> w[i] >> v[i];
    vector<vi> dp(n+1, vi(1e5+1, 1e18));            // dp[i][j] = min weight needed to get j profit from first i elements

    ll p = v[1];
    for(ll i = 1; i <= n; i++){
        dp[i][v[i]] = w[i];
        p += v[i];
        for(ll j = 1; j <= p; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(v[i] <= j)
                dp[i][j] = min(dp[i][j], w[i]+dp[i-1][j-v[i]]);
        }
    }
    for(ll i = 1e5; i >= 0; i--){ // Max profit within knapsack weight
        if(dp[n][i] <= x){
            cout << i << endl;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}