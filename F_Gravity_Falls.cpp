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
    vector<vi> a(n);
    ll mx = 0;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        mx = max(mx, k);
        while(k--){ll p; cin >> p; a[i].pb(p);}
    }
    set<ll> id;
    for(ll i = 0; i < n; i++) id.insert(i);
    for(ll j = 0; id.size() > 0; j++){
        ll m = 1e9+10;
        for(auto i = id.begin(); i != id.end(); ){
            if(a[*i].size() < j+1){
                i = id.erase(i); 
                continue;
            }
            m = min(m, a[*i][j]);
            ++i;
        }
        for(auto i = id.begin(); i != id.end(); ){
            if(a[*i][j] != m){
                i = id.erase(i); continue;
            }
            ++i;
        }
        for(ll i = 0; i < n; i++) if(a[i][j] != m) id.erase(i);
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