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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
vi dig(ll x){
    vi a;
    while(x){
        a.pb(x%10);
        x /= 10;
    }
    rev(a);
    return a;
}
void solve(ll tc){
    ll p, n;
    cin >> p >> n;
    vi d(n);
    for(ll i = 0; i < n; i++) cin >> d[i];
    if(p == 0){
        cout << d[0] << endl;
        return;
    }
    vi a = dig(p);
    ll m = a.size();

    ll pw[19];
    pw[0] = 1;
    for(int i = 1; i < 19; i++) pw[i] = pw[i-1] * 10;

    ll ans = LONG_LONG_MAX;
    ll v = 0;
    for(ll i = 0; i < m-1; i++) v = v*10+d[n-1]; // m-1 digit
    if(v) ans = min(ans, p-v);

    v = d[0];
    if(d[0] == 0 && n > 1) v = d[1];
    for(ll i = 0; i < m; i++) v = v*10+d[0];     // m+1 digit
    if(v) ans = min(ans, v-p);

    // closest bigger  [go with equal till possible and also make the number bigger at that digit and consider that answer]
    v = 0;
    for(ll i = 0; i < m; i++){
        ll id = lower_bound(d.begin(), d.end(), a[i])-d.begin();
        // cout << i << " " << id << endl; 
        if(id == n) break;
        if(d[id] == a[i]){
            if(id+1 < n){
                ll k = v*10+d[id+1];
                k = k*pw[m-i-1];
                k += ((pw[m-1-i]-1)/9)*d[0]; // one larger digit and remaining are the smallest digit
                ans = min(ans, k-p);
            }
            v = v*10+a[i];
        }
        else{
            ll k = v*10+d[id];
            k = k*pw[m-i-1];
            k += ((pw[m-1-i]-1)/9)*d[0];
            ans = min(ans, k-p);
            break;                  // a[i] not found
        }
    }
    if(v == p){
        cout << 0 << endl; 
        return;
    }

    // closest smaller [go with equal (till possible) also consider making it smaller from that digit]
    v = 0;
    for(ll i = 0; i < m; i++){
        if(d[0] > a[i]) break;    // no smaller or equal digit

        ll id = lower_bound(d.begin(), d.end(), a[i])-d.begin();
        
        if(id-1 >= 0){
            ll k = v*10+d[id-1];
            k = k*pw[m-i-1];
            k += ((pw[m-1-i]-1)/9)*d[n-1];  // one smaller digit and remaining are the largest digit
            ans = min(ans, p-k);
        }
        if(id < n && d[id] == a[i]) v = v*10+a[i];
        else break;
    }
    if(v == p)
    ans = 0;
    cout << ans << endl;
}
// greedily select a bigger digit and make all next digits the smallest and consider that answer (same for the smaller case)
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