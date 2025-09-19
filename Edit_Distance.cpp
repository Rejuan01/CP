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
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    vector<vi> dp(n+1, vi(m+1)); // dp[i][j] = edit distance for fist i elements of a and j elements of b
    for(ll i = 1; i <= n; i++) dp[i][0] = i;
    for(ll i = 1; i <= m; i++) dp[0][i] = i;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]})+1; // replacing one char or deleting from any of the string
            }
        }
    }
    cout << dp[n][m] << endl;
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