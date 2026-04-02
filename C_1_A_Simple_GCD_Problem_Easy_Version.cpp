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
    vi a(n), b(n);
    ll g  = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    for(ll i = 0; i < n; i++) cin >> b[i];
    ll cnt = 0;
    for(ll i = 1; i < n-1; i++){
        ll x = __gcd(a[i], a[i-1]);
        ll y = __gcd(a[i], a[i+1]);
        ll k = x*y/__gcd(x, y);
        if(a[i] > k) cnt++;
    }
    if(a[0] > __gcd(a[0], a[1])){
        cnt++;
    }
    if(a[n-1] > __gcd(a[n-1], a[n-2])){
        cnt++;
    }
    cout << cnt << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("task.in", "r", stdin);
    // freopen("task.out", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}