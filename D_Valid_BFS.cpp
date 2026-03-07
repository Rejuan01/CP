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
void solve(ll tc){
    ll n;
    cin >> n;
    set<ll> adj[n+1];
    vi a(n), b(n+1);
    vector<bool> vis(n+1);
    for(ll i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 1;
    while(r < n){
        ll cnt = 0;
        while(r < n && adj[a[l]].count(a[r])){
            cnt++;
            r++;
        }
        if(a[l] != 1) cnt++;         // counted the parant
        if(cnt != adj[a[l]].size()){
            no; return;
        }
        l++;
    }
    yes;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}