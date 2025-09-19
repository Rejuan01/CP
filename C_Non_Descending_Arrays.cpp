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
const ll mod = 998244353;
void solve(){
    ll n;
    cin >> n;
    vi a(n+1), b(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) cin >> b[i];
    ll x = 1;
    for(ll i = 0; i < n; i++){
        ll x1 = a[i], y1 = b[i], x2 = a[i+1], y2 = b[i+1];
        if(x2 < min(x1, y1) || y2 < min(x1, y1)){
            cout << 0 << endl; return;
        }
        if(x2 >= max(x1, y1) && y2 >= max(x1, y1)){
            x *= 2;
            x %= mod;
        }
    }
    cout << x << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}