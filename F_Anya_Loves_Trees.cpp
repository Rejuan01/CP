#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

vector<vi> adj;
vi a, mx, mn, cnt;
bool flag = 0;

void dfs(ll u){

    if(flag) return;

    ll bad = 0, m = 0;

    for(auto v: adj[u]){
        
        dfs(v);

        cnt[u] += cnt[v];
        mx[u] = max(mx[u], mx[v]);
        mn[u] = min(mn[u], mn[v]);

        if(m > 0 && mn[v] != m+1){  // min of current child need to be max of previous child + 1
            bad++;
        }
        m = mx[v];
    }
    if(adj[u].size() == 0){
        mx[u] = a[u];
        mn[u] = a[u];
        cnt[u] = 1;
    }
    if(bad > 1 || mx[u]-mn[u] != cnt[u]-1){
        flag = 1;
    }
}

void solve(ll tc){
    ll n;
    cin >> n;

    adj.assign(n+1, {});
    a.assign(n+1, 0);
    mx.assign(n+1, 0);
    mn.assign(n+1, 1e9);
    cnt.assign(n+1, 0);
    flag = 0;

    for(ll i = 2; i <= n; i++){
        ll p;
        cin >> p;
        adj[p].pb(i);
    }   

    for(ll i = 1; i <= n; i++) cin >> a[i];

    dfs(1);
    
    if(flag) no;
    else yes;
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