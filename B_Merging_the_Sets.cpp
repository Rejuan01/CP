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
    vi c(m+1);
    vector<vi> a(n);
    for(ll i = 0; i < n; i++){
        ll l; cin >> l;
        for(ll j = 0; j < l; j++){
            ll x; cin >> x; 
            a[i].pb(x);
            c[x]++;
        }
    }
    for(ll i = 1; i <= m; i++){
        if(c[i] == 0){
            no; return;
        }
    }
    ll p = 0;
    for(ll i = 0; i < n; i++){
        bool flag = 0;
        for(auto it: a[i]){
            if(c[it] < 2){
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        p++;
        if(p > 1){
            yes; return;
        }
    }
    no;
    
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