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
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for(ll c = 1; c <= n; c++){
        ll b; cin >> b;
        mp[c-b] += b;
    }
    ll ans = LONG_LONG_MIN;
    for(auto &[k, v]: mp){
        ans = max(ans, v);
    }
    cout << ans << endl;
}
// c[i+1] - b[i+1] = c[i] - b[i]
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}