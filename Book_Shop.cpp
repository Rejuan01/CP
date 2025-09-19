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
    vi c(n+1), p(n+1);
    for(ll i = 1; i <= n; i++) cin >> c[i]; // cost
    for(ll i = 1; i <= n; i++) cin >> p[i]; // no of pages

    // vector<vi> dp(n+1, vi(x+1, 0)); 
    // dp[i][j] = max page can be got from first i books within j cost
    vi prev(x+1); // dp[i-1]
    for(ll i = 1; i <= n; i++){
        vi current(x+1); // dp[i]
        for(ll j = 1; j <= x; j++){
            ll cost = c[i], pages = p[i];
            ll k1 = prev[j]; // not taking the i'th book
            ll k2 = 0;
            if(j-cost >= 0) k2 = prev[j-cost] + pages; // taking the i'th book if possible
            current[j] = max(k1, k2);
        }
        prev = current;
    }
    cout << prev[x] << endl; 
}
// space optimization:
// current = dp[i]
// previous = dp[i-1]
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