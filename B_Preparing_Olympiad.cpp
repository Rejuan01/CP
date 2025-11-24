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
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(ll k = 0; k < (1<<n); k++){
        if(__builtin_popcountll(k) < 2) continue;
        ll mx = 0, mn = 1e18;
        ll s = 0;
        for(ll i = 0; i < n; i++){
            if((1<<i)&k){
                // cout << a[i] << " ";
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
                s += a[i];
            }
        }
        cout << endl;
        // cout << mn << " - " << mx << endl;
        if(s < l || s > r || mx-mn < x) continue;
        ans++;
    }
    cout << ans << endl;
    
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