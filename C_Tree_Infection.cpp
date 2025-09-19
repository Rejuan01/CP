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
    vi a;
    vector<vi> adj(n+1);
    for(ll i = 2; i <= n; i++){
        ll p; cin >> p;
        adj[p].pb(i);
    }
    for(ll i = 1; i <= n; i++) if(adj[i].size()) a.pb(adj[i].size());
    a.pb(1);
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0, c = 0;
    for(auto it: a){
        ans = max(ans, it+c);
        c++;
    }
    ll s = 0;
    for(ll i = 0; i < a.size(); i++){
        a[i] = max(0LL, a[i] - (c - i));
        s += a[i];
    }
    while(s != 0){
        c++;
        ll idx = 0, m = 0;
        s = 0;
        for(ll i = 0; i < a.size(); i++){
            if(a[i] > m){
                idx = i; m = a[i];
            }
            if(a[i] != 0) a[i]--;
            s += a[i];
        }
        if(a[idx] != 0){
            a[idx]--; s--;
        }
    }
    cout << c << endl;

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