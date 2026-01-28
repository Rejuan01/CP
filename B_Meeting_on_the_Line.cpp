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
pair<double, double> check(vi &a, vi &t, double m){
    ll n = a.size();
    double x = -1e18, y = 1e18;
    for(ll i = 0; i < n; i++){
        if(t[i] > m) return {1, -1};
        double k = (m-t[i]);
        x = max(x, a[i]-k);
        y = min(y, a[i]+k);
    }
    return {x, y};   // in which range they can meet
}
void solve(){
    ll n;
    cin >> n;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    double l = -1, r = 1e16+1;
    while(l+ 1e-6 < r){           // to find min time at which they can meet
        double m = (l+r)/2;
        auto p = check(a, b, m);
        if(p.first <= p.second) r = m;   // in time m, they can meet in a valid place
        else l = m;
    }
    auto p = check(a, b, r);
    cout << fixed << setprecision(7) <<  p.first << endl;
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