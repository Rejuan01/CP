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
    ll p, n, x, y;
    cin >> p >> n >> x >> y;
    if(p == 0){
        cout << x << endl;    
        return;
    }
    ll pw[19];
    pw[0] = 1;
    for(int i = 1; i < 19; i++) pw[i] = pw[i-1] * 10;
    vi a = dig(p);
    n = a.size();
    ll ans = LONG_LONG_MAX, v = 0;

    ll v1 = 0;
    for(ll i = 0; i < n-1; i++) v1 = v1*10+y; // n-1 digit number
    if(v1) ans = min(ans, p-v1);

    v1 = x;
    if(x == 0) v1 = y;
    for(ll i = 0; i < n; i++) v1 = v1*10+x; // n+1 digit number
    ans = min(ans, v1-p);

    for(ll i = 0; i < n; i++){          // try to set a minimum number >= p
        if(y < a[i]) break;
        else if(y == a[i]) v = v*10+y;
        else if(a[i] >= x && a[i] < y){
            ll k = v*10+y;
            k *= pw[n-i-1];
            k += ((pw[n-i-1]-1) / 9) * x;
            ans = min(ans, k-p);

            if(x == a[i]) v = v*10 + x;
            else break;
        }
        else{ // a[i] < x
            ll k = v*10+x;
            k *= pw[n-i-1];
            k += ((pw[n-i-1]-1) / 9) * x;
            ans = min(ans, k-p);
            break;
        }
    }
    if(v == p){
        cout << 0 << endl; return;
    }
    v = 0;
    for(ll i = 0; i < n; i++){     // try to set a maximum number <= p
        if(x > a[i]) break;
        else if(x == a[i]) v = v*10+x;
        else if(a[i] > x && a[i] <= y){
            ll k = v*10+x;
            k *= pw[n-i-1];
            k += ((pw[n-i-1]-1) / 9) * y;
            ans = min(ans, p-k);

            if(y == a[i]) v = v*10 + y;
            else break;
        }
        else{ // a[i] > y
            ll k = v*10+y;
            k *= pw[n-i-1];
            k += ((pw[n-i-1]-1) / 9) * y;
            ans = min(ans, p-k);
            break;
        }
    }
    if(v == p) ans = 0;
    cout << ans << endl;
}
// for each digit keep taking the same if possible or make it bigger digit (if possible) and smaller for the remaining digits and take the difference 
// same for smaller case
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
