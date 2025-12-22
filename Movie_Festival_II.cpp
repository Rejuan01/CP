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
    vp v;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v.pb({b, a});
    }
    sort(v.begin(), v.end());
    // for(auto &[x, y]: v) cout << x << " " << y << endl;
    multiset<ll> st;
    ll cnt = n;
    for(ll i = 0; i < n; i++){
        auto it = st.upper_bound(v[i].second);
        if(it == st.begin()){
            if(st.size() < k) st.insert(v[i].first);
            else cnt--;
        }
        else{
            --it;
            st.erase(it);
            st.insert(v[i].first);
        }
    }
    cout << cnt << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}