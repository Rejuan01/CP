#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    ll m = (1<<n);
    set<ll> st;
    vi a;
    for(ll i = 0; i < m; i++){
        a.pb(i);
        st.insert(i);
    }
    map<ll, set<ll>, greater<ll>> mp;
    for(ll i = n; i > 0; i--){
        ll x = (1<<i)-1;
        for(ll j = 0; j < m; j++){
            if((a[j]&x) == x){
                mp[i].insert(a[j]);
                st.erase(a[j]);
                a[j] = 0;
            }
        }
    }
    for(auto &[k, s]: mp){
        for(auto it: s) cout << it << " ";
    }
    for(auto it: st) cout << it << " ";
    cout << endl;
    
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