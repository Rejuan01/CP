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
    ll n;
    cin >> n;
    vi a(n);
    multiset<ll> st;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    ssort(a);
    ll l = 0, r = n+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        set<ll> tm;
        for(ll i = 0; i < m; i++) tm.insert(i);  // values need to get mex >= m
        for(ll i = 0; i < n && tm.size(); i++){
            if(tm.count(a[i])){
                tm.erase(a[i]); 
            }
            else{
                ll k = (a[i]-1)/2;
                if(*tm.begin() <= k){
                    tm.erase(tm.begin());
                }
            }
        }
        if(tm.size() == 0) l = m;
        else r = m;
    }
    cout << l << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}