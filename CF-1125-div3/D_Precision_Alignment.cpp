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
const ll inf = LONG_LONG_MAX;
void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n), c(n);
    ll mn = 2e18;

    ll l = 0, r = 2e18;

    for(ll i = 0; i < n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        if(x > y || x > z || y > z){
            a[i] = x+y+z;
        }
        else if(x == y && x == z){
            mn = min(mn, x+y+z);
            c[i] = 1;
        }
        else{
            ll d = min({y-x, z-x, z-y})+1;
            a[i] = x+y+z;
            b[i] = d;
        }
        l = min(l, x+y+z);
    }

    while(l+1 < r){
        ll m = l + (r-l)/2;
        ll cnt = 0;
        for(ll i = 0; i < n; i++){
            if(c[i] == 1 || m <= a[i]) continue;
            cnt += m - a[i] + 2*b[i];
            if(cnt > k) break;
        }
        if(cnt > k) r = m;
        else l = m;
    }

    l = min(mn, l);
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