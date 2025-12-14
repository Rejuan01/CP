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
    st.insert({0, n});
    map<ll, ll, greater<ll>> mp;
    mp[n]++;
    while(m--){
        ll x; cin >> x;
        auto it = st.lower_bound(x);
        ll l = *prev(it);
        ll r = *it;
        st.insert(x);
        mp[r-l]--;
        if(mp[r-l] == 0) mp.erase(r-l);
        mp[x-l]++;
        mp[r-x]++;
        cout << mp.begin()->first << " ";
    } cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}