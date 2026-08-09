#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    vi b(n);
    for(ll i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++) cin >> a[i][j];
    }

    multiset<ll, greater<ll>> st;
    ll ans = m;
    for(ll i = n-1; i >= 0; i--){
        for(ll j = 0; j < m; j++){
            st.insert(a[i][j]);
            if(st.size() > m) st.erase(prev(st.end()));
        }
        ll k = b[i], c = 0;
        for(auto it: st){
            k -= it;
            c++;
            if(k <= 0) break;
        }
        ans = min(ans, c);
        if(ans == 1) break;
    }

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