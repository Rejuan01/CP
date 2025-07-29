#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, m;
    cin >> n >> m;
    vi a(m);
    for(ll i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll lb[n+1];
    for(ll i = 1; i < n; i++){
        ll idx = lower_bound(a.begin(), a.end(), i) - a.begin();
        lb[i] = idx;
    }
    ll ans = 0;
    for(ll i = 1; i <= n/2; i++){ // paint 'i' planks with one and 'n-i' with another color
        if(lb[i] == m) break;
        if(lb[n-i] == m) continue;
        ll x = lb[n-i]-lb[i];
        ll y = m - lb[n-i];   
        ans += 2*x*y;
        if(2*i == n){
            ans += y*(y-1); // yP2
        }else ans += y*(y-1)*2; // 2* yP2
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}