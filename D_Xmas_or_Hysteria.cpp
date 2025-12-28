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
    ll n, m;
    cin >> n >> m;
    vector<vi> a;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        a.pb({x, i+1});
    }
    rsort(a);
    if(m > n/2){
        cout << -1 << endl;
        return;
    }
    if(m == 0){
        ll l = 0, r = n-1;
        ll idx = 1, s = 0;
        while(idx < n && s < a[0][0]) s += a[idx++][0];
        if(s < a[0][0]){
            cout << -1 << endl; return;
        }
        cout << n-1 << endl;
        for(ll i = n-1; i >= idx; i--){
            cout << a[i][1] << " " << a[i-1][1] << endl;
        }
        for(ll i = 1; i < idx; i++){
            cout << a[i][1] << " " << a[0][1] << endl;
        }
        return;
    }
    cout << n-m << endl;
    for(ll i = n-2; i >= 2*m-1; i--){
        cout << a[i][1] << " " << a[i+1][1] << endl;
    }
    for(ll i = 0; i < m; i++){
        cout << a[i][1] << " " << a[i+m][1] << endl;
    }
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