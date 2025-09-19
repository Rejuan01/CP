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
    ll n;
    cin >> n;
    vector<set<ll>> adj(n+1);
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vp a;
    for(ll i = 1; i <= n; i++){
        a.pb({adj[i].size(), i});
    }
    sort(a.begin(), a.end(), greater<pr>());
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll v = a[i].second;
        ll cv = a[i].first;
        if(2*cv <= ans) break; // not neceassary
        for(ll j = i+1; j < n; j++){  // this loop runs at max adj[v].size()+1 times
            ll u = a[j].second;
            ll cu = a[j].first;
            if(adj[v].find(u) == adj[v].end()){
                ll s = cv+cu-1; 
                ans = max(ans, s);
                break;
            }
            ll s = cv+cu-2;
            ans = max(ans, s);
        }
    }
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