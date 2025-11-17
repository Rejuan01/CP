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
    set<ll> st;
    ll xx;
    for(ll i = 0; i < n; i++){
        cin >> xx;
        st.insert(xx);
    }
    set<pair<pr, ll>> r; 
    for(ll i = 0; i < m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        r.insert({{x, y}, z});
    }
    while(1){
        ll c = 0;
        set<pair<pr, ll>> tm;
        for(auto &i: r){
            auto i1 = st.find(i.first.first);
            auto i2 = st.find(i.first.second);
            if((i1 != st.end()) && (i2 != st.end())){
                st.insert(i.second);
                // auto it1 = i;
                // r.erase(it1);
                tm.insert(i);
                c++;
            }
        }
        for(auto i: tm){
            r.erase(i);
        }
        if(c == 0 || r.size() == 0) break;
    }
    cout << st.size() << endl;
    
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