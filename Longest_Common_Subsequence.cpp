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
    ll n, m;
    cin >> n >> m;
    vi a(n+1), b(m+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= m; i++) cin >> b[i];
    vector<vi> dp(n+1, vi(m+1)); // dp[i][j] = LCS len for first i numbs of a and j numbs of b
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vi ans;
    ll i = n, j = m;
    // backtrack
    while(i > 0 && j > 0){
        if(a[i] == b[j]){
            ans.pb(a[i]);
            i--; j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]) i--; // dp[i][j] == dp[i-1][j]
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout << dp[n][m] << endl;           // ans.size()
    for(auto it: ans) cout << it << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}