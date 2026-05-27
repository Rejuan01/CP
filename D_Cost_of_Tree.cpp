#include<bits/stdc++.h>
using namespace std;

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

vector<vi> adj;
vi subtree, mxd, tot, res, a, mxgain;
void dfs(ll u, ll p){
    multiset<ll> dep;
    dep.insert(0);
    subtree[u] += a[u];
    for(auto v: adj[u]){
        if(v != p){
            dfs(v, u); 
            subtree[u] += subtree[v]; 
            dep.insert(mxd[v]); 
            mxd[u] = max(mxd[u], mxd[v]); 
            tot[u] += tot[v]+subtree[v];                 // tot is the result without move 
            mxgain[u] = max(mxgain[u], mxgain[v]);
        }
    }
    mxd[u]++; 
    ll ans = 0;
    for(auto v: adj[u]){
        if(v == p) continue;
        dep.erase(dep.find(mxd[v]));
        ll val = (*dep.rbegin())*subtree[v]; // gain by moving v to maxdepth (without v)
        mxgain[u] = max(mxgain[u], val); 
        dep.insert(mxd[v]); 
    }
    res[u] = tot[u] + mxgain[u];
}
void solve(ll tc){
    ll n;
    cin >> n;
    adj.assign(n+1, {});
    subtree.assign(n+1, 0);
    mxd.assign(n+1, 0); 
    tot.assign(n+1, 0);
    res.assign(n+1, 0);
    mxgain.assign(n+1, 0);
    a.assign(n+1, 0);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    for(ll i = 1; i <= n; i++) cout << res[i] << " "; 
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}