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
    ll n, q;
    cin >> n >> q;
    vi a(n+1), p(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1){
            if(a[i] == a[i-1]) p[i]++;
            p[i] += p[i-1];
        }
    }
    for(ll i = 1; i <= n; i++) a[i] += a[i-1];
    while(q--){
        ll l, r; cin >> l >> r;
        ll s1 = a[r]-a[l-1];
        ll s0 = r-l+1 - s1;
        if(s1%3 != 0 || s0%3 != 0){
            cout << -1 << endl; continue;
        }
        if(p[r]-p[l]){
            cout << (r-l+1)/3 << endl;
        }
        else cout << (r-l+1)/3 +1 << endl;
    }
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