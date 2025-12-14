#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(){
    ll n, m;
    cin >> n >> m;
    vi a(n+1), v(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> v[i];
        a[v[i]] = i+1;
    }
    ll ans = 1;
    for(ll i = 1; i < n; i++) if(a[i+1] < a[i]) ans++;
    while(m--){
        ll x, y, p, q; cin >> p >> q;
        if(p > q) swap(p, q);
        x = v[p], y = v[q];

        if(x > 1 && a[x] < a[x-1] && a[x-1] <= a[y]) ans--;
        if(x < n && a[x] < a[x+1] && a[x+1] <= a[y]) ans++;

        if(y > 1 && a[x] < a[y-1] && a[y-1] < a[y]) ans++;
        if(y < n && a[x] < a[y+1] && a[y+1] < a[y]) ans--;

        swap(a[x], a[y]);
        swap(v[p], v[q]);

        cout << ans << endl;

    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}