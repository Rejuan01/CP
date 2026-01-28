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
bool check(vi &a, vi &v, double t){
    double x = 0, y = 1e9;
    ll n = a.size();
    for(ll i = 0; i < n; i++){
        x = max(x, a[i]-t*v[i]);
        y = min(y, a[i]+t*v[i]);
    }
    return x <= y;    // they can meet in a valid range [x, y]
}
void solve(){
    ll n;
    cin >> n;
    vi a(n), v(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> v[i];
    double l = -1e-6, r = 1e9;
    while(l+1e-6 < r){
        double m = (l+r)/2;
        if(check(a, v, m)) r = m;    // if they can meet within time m
        else l = m;
    }
    cout << fixed << setprecision(7) << r << endl;
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