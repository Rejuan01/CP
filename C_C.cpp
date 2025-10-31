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
    vi a(n+1), s(n+1);
    multiset<ll> st;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1]+a[i];
        st.insert(s[i]);
    }
    // for(auto it: s) cout << it << " ";
    // cout << endl;
    if(s[n] < 0){
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    if(*st.begin() >= 0) ans++;
    // cout << ans << endl;

    for(ll i = 1; i < n; i++){
        if(*st.begin() >= s[i]){
            // cout << " ** " << s[i] << endl;
            ans++;
        }
        auto it = st.find(s[i]);
        st.erase(it);
        st.insert(s[n]+s[i]);
    }
    cout << ans << endl;
    
    
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