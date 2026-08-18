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
    ll s, q;
    cin >> s >> q;
    vi a;
    a.pb(1); a.pb(s);
    for(ll i = 2; i*i <= s; i++){
        if(s%i == 0){
            a.pb(i);
            if(i*i != s) a.pb(s/i);
        }
    }
    ssort(a);
    vi b = a;
    rev(b);
    ll n = b.size();
    for(ll i = 1; i < n; i++){
        b[i] = b[i]*(a[i]-a[i-1]) + b[i-1];  
        // cout << b[i] << " ";
    }
    // cout << endl;

    while(q--){
        ll x, y;
        cin >> x >> y;
        ll id = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;

        if((id+1 < n && s/a[id+1] >= y) || (a[id] == x && s/a[id] >= y)){
            cout << x*y << endl;
            continue;
        } 

        ll k = b[id];
        // cout << k << endl;
        if(id+1 < n){                // add remaining on the right of x
            ll y = s/a[id+1];
            k += y*(x-a[id]);
        }
        // cout << k << endl;
        id = upper_bound(a.begin(), a.end(), y) - a.begin();
        if(id < n){                                           // erase upper segment above y
            ll val = s/a[id];
            id = lower_bound(a.begin(), a.end(), val) - a.begin();
            k -= b[id];
            k += y*a[id];
        }
        cout << k << endl;
    }
    
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