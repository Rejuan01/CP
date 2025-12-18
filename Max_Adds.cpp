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
bool check(vi &a, vi &b, ll x){
    ll k = x, n = a.size();
    bool flag = 1;
    for(ll i = 0; i < n; i++){
        if(b[i]+k < a[i]) flag = 0;
        if(!flag) break;
        k = max(a[i], b[i]+k);
    }
    return flag;
}
ll calc(vi &a, vi &b, ll k){
    for(ll i = 0; i < a.size(); i++) k = max(a[i], k+b[i]);
    return k;
}
void solve(){
    ll n, m;
    cin >> n >> m;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    ll l = 0, r = 1e9;
    while(l+1 < r){                 // find min value of r from where the output becomes linear
        ll mid = (l+r)/2;
        if(check(a, b, mid)) r = mid;
        else l = mid;
    }
    ll ans = 0;
    if(r > m) ans = calc(a, b, 0)*m; // did not reach the linear region ;(
    else ans = calc(a, b, 0)*(r-1) + calc(a, b, r)*(m-r+1) + (m-r)*(m-r+1)/2; 
    cout << ans << endl;
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