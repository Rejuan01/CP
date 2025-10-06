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
    ll n, k;
    cin >> n >> k;
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    vi dp(n+1);                                  // dp[i] = cost to reach the i th stone
    for(ll i = 2; i <= n; i++){
        ll x = 1e18;
        for(ll j = 1; j <= k && j < i; j++){
            x = min(x, dp[i-j]+abs(a[i]-a[i-j])); // if comes from i-j th stone
        }
        dp[i] = x;
    }
    cout << dp[n] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}