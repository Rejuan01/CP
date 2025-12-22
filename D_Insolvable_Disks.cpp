#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << 0 << endl; return;
    }
    ll x = 0, y = a[1]-a[0];  // valid range of radius (x, y)
    ll cnt = 0;
    for(ll i = 1; i < n; i++){
        if(i == n-1){
            cnt++; continue; // last point can be added anyhow
        }
        ll d = a[i]-a[i-1];
        ll p = d-y, q = d-x; // new range
        ll d2 = a[i+1]-a[i];
        if(p < d2){
            cnt++;
            x = p; y = min(q, d2);
        }else{
            x = 0, y = d2;
        }
    }
    cout << cnt << endl;
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