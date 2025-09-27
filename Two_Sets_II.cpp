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
const ll mod = 1e9+7;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    ll s = n*(n+1)/2;
    if(s&1){
        cout << 0 << endl; return 0;
    }
    s /= 2;
    vector<vi> dp(n+1, vi(s+1)); // no of ways to get j sum with first i elements
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(ll j = 1; j <= s; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= i) dp[i][j] += dp[i-1][j-i];
            dp[i][j] %= mod;
        }
    }
    ll inv2 = (mod + 1) / 2;
    cout << (dp[n][s] * inv2) % mod << endl;
    return 0;
}