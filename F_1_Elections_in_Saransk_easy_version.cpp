#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mxn = 5e5, mod = 1e9+7;
ll spf[mxn+1];
void init(){
    for(ll i = 1; i <= mxn; i++) spf[i] = i;
    for(ll i = 2; i*i <= mxn; i++){
        if(spf[i] == i)                         // prime
        for(ll j = i*i; j <= mxn; j += i){
            spf[j] = i;
        }
    }
}

void solve(ll tc){
    ll n, k;
    cin >> n >> k; 
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mp;
    for(auto it: a){
        while(it != 1){
            ll x = spf[it];
            mp[x]++;
            it /= x;
        }
    }
    ll ans = 1;
    for(auto [p, q]: mp){
        // cout << p << " " << q << endl;
        ans = ans*(q+1) % mod;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    init();
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}