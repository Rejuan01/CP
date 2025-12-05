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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    set<ll> st, mrk;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    ssort(a);
    vi ans;
    for(ll i = 0; i < n; i++){
        if(mrk.find(a[i]) != mrk.end()) continue;
        for(ll j = a[i]; j <= k; j+=a[i]){
            if(st.find(j) == st.end()){
                cout << -1 << endl;
                return;
            } else mrk.insert(j);
        }
        ans.pb(a[i]);
    }
    cout << ans.size() << endl;
    for(auto it: ans) cout << it << " ";
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