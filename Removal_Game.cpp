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
    ll n;
    cin >> n;
    vi a(n+1);
    ll s = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    vector<vi> dp(n+1, vi(n+1)); // dp[i][j] = (first movers score - second movers score) in that range
    for(ll i = n; i >= 1; i--){
        dp[i][i] = a[i];
        for(ll j = i+1; j <= n; j++){
            dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }
    cout << (s+dp[1][n])/2 << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}