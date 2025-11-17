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
    vector<vi> a(n, vi(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++) cin >> a[i][j];
    }
    vi r(n), c(m);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            r[i] = (r[i]^a[i][j]);
            c[j] = (c[j]^a[i][j]);
        }
    }
    ll ans = 0;
    for(auto it: r) ans += it;
    for(auto it: c) ans += it;
    ll p = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll x = r[i]^a[i][j];
            ll y = c[j]^a[i][j];
            ll z = (x^y)-r[i]-c[j];
            p = min(p, z);
        }
    }
    cout << ans+p << endl;
    
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}