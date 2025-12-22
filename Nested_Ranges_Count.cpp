#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
typedef tree<ll, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    pbds ends;
    for(auto &p: points){
        ll y = abs(p[1]);
        b[p[2]] = ends.size() - ends.order_of_key(y); // How many points are >= y
        ends.insert(y);
    }
    rev(points);
    ends.clear();
    for(auto &p: points){
        ll y = abs(p[1]);
        a[p[2]] = ends.order_of_key(y+1); // How many ends points are < y+1 (<=y)
        ends.insert(y);
    }
    for(auto it: a) cout << it << " ";
    cout << endl;
    for(auto it: b) cout << it << " ";
    cout << endl;
}
// pnds.order_of_key(x) = no of elements less than x (even if x doesn't exists)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}