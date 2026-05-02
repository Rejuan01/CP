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
ll cal(vi &a, ll x, ll y){
    ll n = a.size();
    set<ll> st;
    for(ll i = 0; i <= n/2; i++) st.insert(i);
    ll l = x, r = y;
    while(l <= r){
        if(a[l] != a[r]) return 0;
        st.erase(a[l]);
        l++;
        r--;
    }
    l = x, r = y;
    while(l >= 0 && r < n){
        if(a[l] != a[r]) break;
        st.erase(a[l]);
        l--;
        r++;
    }
    return *st.begin();
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(2*n);
    ll x = -1, y = -1;
    for(ll i = 0; i < 2*n; i++){
        cin >> a[i];
        if(a[i] == 0){
            if(x == -1) x = i;
            else y = i;
        }
    }
    ll ans = cal(a, x, y);
    ans = max(ans, cal(a, x, x));
    ans = max(ans, cal(a, y, y));
    cout << ans << endl;
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