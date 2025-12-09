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
    vi a(n);
    set<pr> st;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]) st.insert({a[i], i+1}); 
    }
    vp ans;
    while(st.size()){
        auto it = st.rbegin();
        pr p = *it;
        st.erase(*it);
        vp v;
        for(auto i = st.rbegin(); i != st.rend(); ++i){
            v.pb(*i);
            p.first--;
            if(p.first == 0) break;
        }
        if(p.first){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        for(auto &i: v){
            st.erase(i);
            i.first--;
            ans.pb({p.second, i.second});
            if(i.first) st.insert(i);
        } 
    }
    cout << ans.size() << endl;
    for(auto it: ans) cout << it.first << " " << it.second << endl;
    
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