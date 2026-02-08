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
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vi a(n);
    vector<vi> v;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x == 1) v.pb({x, a[i]});
        else v.pb({x, -a[i]});
    }
    ssort(v);
    for(auto &it: v) it[1] = abs(it[1]); // Trying to format in a way that high memory (a[i]) applications of both convenience point 1 and 2 stay besides
    ll s = 0, c = 0, ans = 1e9;
    ll l = 0, r = 0;
    while(r < n){
        s += v[r][1];
        c += v[r][0];
        while(s-v[l][1] >= m){
            c -= v[l][0];
            s -= v[l][1];
            l++;
        }
        if(s >= m) ans = min(ans, c);
        r++;
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}