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
    vi a(n), b(n);
    multiset<ll> st;
    for(ll i = 0; i < n; i++) cin >> a[i];
    st.insert(a[0]);
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        st.insert(b[i]);
    }
    set<pr> p;
    ll x = *st.begin(), y = *st.rbegin();
    p.insert({y, x});
    for(ll i = 1; i < n; i++){
        st.erase(st.find(b[i-1]));
        st.insert(a[i]);
        x = *st.begin(), y = *st.rbegin();
        p.insert({y, x});
    }
    ll ans = 0;
    for(ll l = 1; l <= 2*n && p.size(); l++){
        while(p.size() && p.begin()->second < l){
            p.erase(p.begin());
        }
        if(p.size()){
            ll r = p.begin()->first;
            ans += 2*n-r+1;
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