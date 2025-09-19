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
#define ay cout<<"Ayush"<<endl
#define as cout<<"Ashish"<<endl
void solve(){
    ll n, x;
    cin >> n >> x;
    vi a(n);
    vector<vi> adj(n+1);
    for(ll i = 0; i < n-1; i++){
        ll p, q; cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    ll k = adj[x].size();
    if(k < 2){
        ay; return;
    }
    if(n&1) as;
    else ay;
    
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