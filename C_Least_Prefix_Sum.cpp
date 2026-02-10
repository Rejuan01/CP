#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll cnt = 0, s = 0;
    multiset<ll> st;
    for(ll i = m; i < n; i++){
        s += a[i];
        if(a[i] < 0) st.insert(a[i]);
        while(s < 0){
            s -= 2*(*st.begin());       // previously added values substracted twice ;(
            st.erase(st.begin());
            cnt++;
        }
    }
    st.clear();
    s = 0;
    for(ll i = m-1; i > 0; i--){
        s += a[i];
        if(a[i] > 0) st.insert(a[i]);
        while(s > 0){
            s -= 2*(*st.rbegin());    
            st.erase(prev(st.end()));
            cnt++;
        }
    }
    cout <<cnt << endl;
}
// In the given array, need to keen all the prefix sum of the subarray [m+1, n] positive (or 0)
// also need to keep all suffix sum of the subarray [2, m] negative (or 0)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}