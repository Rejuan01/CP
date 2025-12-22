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
void solve(){
    ll n;
    cin >> n;
    vector<vi> points;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        points.pb({x, -y, i});
    }
    vi a(n), b(n);
    ssort(points); 
    set<ll> ends;
    for(auto &p: points){
        ll y = abs(p[1]);
        if(ends.size() && *ends.rbegin() >= y) b[p[2]] = 1;
        ends.insert(y);
    }
    rev(points);
    ends.clear();
    for(auto &p: points){
        ll y = abs(p[1]);
        if(ends.size() && *ends.begin() <= y) a[p[2]] = 1;
        ends.insert(y);
    }
    for(auto it: a) cout << it << " ";
    cout << endl;
    for(auto it: b) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}