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
pair<double, double> check(vi &a, vi &v, double t){
    double x = -1e9, y = 1e9;
    ll n = a.size();
    for(ll i = 0; i < n; i++){
        double d = t*v[i];
        x = max(x, a[i]-d);
        y = min(y, a[i]+d);
    }
    return {x, y};  // within t time at which range of space, they can meet
}
void solve(){
    ll n;
    cin >> n;
    vi a(n), v(n);
    for(ll i = 0; i < n; i++) cin >> a[i] >> v[i];
    double l = -1, r = 2e18+2;
    while(l+1e-6 < r){             // find the min time
        double m = (l+r)/2;
        auto p = check(a, v, m);
        if(p.first <= p.second) r = m; // they can meet in a valid space within m time
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