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
    ll n;
    cin >> n;
    vi a(n);
    vi p, q;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 4; i < n; i++){
        ll x = a[i-4]+a[i-2]-a[i];
        p.pb(x);
        mp[x]++;
    }
    ll m = p.size(), ans = 0;
    for(ll i = 0; i < m; i++){
        ll k = 0;
        if(i-4 >= 0 && p[i] == p[i-4]) k++;
        if(i-2 >= 0 && p[i] == p[i-2]) k++;
        if(i+4 < m && p[i] == p[i+4]) k++;
        if(i+2 < m && p[i] == p[i+2]) k++;
        ans += mp[p[i]]-k-1;
        // cout << k << endl;
        // cout << i << " " << ans << endl;
    }
    cout << ans/2 << endl;
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