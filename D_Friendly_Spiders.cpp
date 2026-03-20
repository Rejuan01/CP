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
void solve(){
    ll n;
    cin >> n;
    vi a(n+1);
    ll mx = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll x, y; cin >> x >> y;
    vi spf(mx+1);                  // smallest prime factor
    for(ll i = 2; i <= mx; i++){
        if(spf[i] == 0){
            for(ll j = i; j <= mx; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
    ll N = n+mx+1;
    vector<vi> adj(N);
    for(ll i = 1; i <= n; i++){
        ll k = a[i];
        while(k > 1){
            ll p = spf[k];
            adj[i].pb(p+n);
            adj[p+n].pb(i);
            while(spf[k] == p) k /= p;
        }
    }   
    vi parant(N, -1), d(N, -1);
    queue<ll> q;
    q.push(x);
    d[x] = 0;
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(auto u: adj[v]){
            if(d[u] == -1){
                d[u] = d[v]+1;
                parant[u] = v;
                q.push(u);
            }
        }
    }
    if(d[y] == -1){
        cout << -1 << endl; return;
    }
    cout << d[y]/2 + 1 << endl;
    vi path;
    for(ll i = y; i != -1 ; i = parant[parant[i]]){
        path.pb(i);
        if(parant[i] == -1) break;
    }
    rev(path);
    for(auto it: path) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}