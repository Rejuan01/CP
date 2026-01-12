#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mod = 998244353;
ll mxn = 2e6;
void solve(){
    ll n, m;
    cin >> n;
    vi a(n);
    vi xc(mxn+1), yc(mxn+1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        xc[a[i]] = x;
    }
    cin >> m;
    vi c(m);
    for(ll i = 0; i < m; i++) cin >> c[i];
    for(ll i = 0; i < m; i++){
        ll x; cin >> x;
        yc[c[i]] = x;
    }
    ll ans = 1;
    for(ll i = 1; i <= mxn; i++){
        ll cnt = xc[i]-yc[i];
        if(cnt < 0){
            cout << 0 << endl; return; 
        }
        if(cnt){
            ans += ans;
            if(ans > mod) ans -= mod; // ans = 2*ans % mod;
        }
    }
    cout << ans << endl;
}
/*
    1. gcd always gets the lower power and lcm gets the higher power from the prime factorization
    2. So, if the powers are different there comes 2 possibilities of original number :)
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}