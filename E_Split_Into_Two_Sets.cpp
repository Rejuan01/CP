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
    vi c(n+1);
    vector<bool> marked(n+1);
    bool flag = 0;
    vector<vi> adj(n+1);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        if(adj[a].size() > 2 || adj[b].size() > 2) flag = 1;
        else if(a == b) flag = 1;
    }
    if(flag){no; return;}
    for(ll i = 1; i <= n; i++){
        if(marked[i]) continue;
        ll k = i;
        ll c = 0;
        while(!marked[k]){
            c++;
            marked[k] = 1;
            for(auto j: adj[k]){
                if(!marked[j]){
                    k = j;
                    break;
                }
            }
        }
        if(c&1){no; return;}
    }
    yes;
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