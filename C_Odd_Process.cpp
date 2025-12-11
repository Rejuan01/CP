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
void solve(){
    ll n;
    cin >> n;
    vi a, b;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x&1) a.pb(x);
        else b.pb(x);
    }
    vi ans(n+1);
    rsort(a);
    rsort(b);
    if(a.size() == 0){
        for(ll i = 0; i < n; i++) cout << 0 << " ";
        cout << endl; return;
    }
    if(b.size() == 0){
        for(ll i = 0; i < n; i++){
            if(i&1) cout << 0 << " ";
            else cout << a[0] << " ";
        } cout << endl;
        return;
    }
    ans[1] = a[0];
    for(ll i = 1; i < b.size(); i++){
        b[i] += b[i-1];
    }
    for(ll i = 2; i <= n; i++){
        if(i-2 < b.size()){
            ans[i] = a[0] + b[i-2];
        }
        else{
            ll x = b.size();
            ll y = i-x-1;
            if(y&1){
                if(y == a.size()-1) ans[i] = 0;
                else{
                    ans[i] = a[0];
                    if(x >= 2) ans[i] += b[x-2];
                }
            }
            else{
                ans[i] = a[0];
                if(x >= 1) ans[i] += b[x-1];
            }
        }
    }
    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    
    
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