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
    vi a(n), b(n), c(n+1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    if(n < 3){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vi ans(n);
    set<ll> st;
    for(ll i = 1; i <= n; i++) st.insert(i);
    for(ll i = 0; i < n; i++){
        auto it = st.begin();
        while(it != st.end() && (*it == b[i] || *it == a[i])) ++it;
        if(it == st.end()) break;
        ans[i] = *it;
        st.erase(it);
    }
    if(ans[n-2] == 0){
        ll x = *st.begin();
        for(ll i = 0; i < n-2; i++){
            if(a[i] != n-1 && b[i] != n-1){
                ans[n-2] = ans[i];
                ans[i] = x;
                break;
            }
        } st.erase(x);
    }
    if(ans[n-1] == 0){
        ll x = *st.begin();
        for(ll i = 0; i < n-1; i++){
            if(a[i] != n && b[i] != n){
                ans[n-1] = ans[i];
                ans[i] = x;
                break;
            }
        }
    }
    for(auto it: ans) cout << it << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}