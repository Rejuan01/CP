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
    vi a(n), b(n), idx(n+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    map<ll, ll> mp; // (shift, number of values matches for that shift)
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        ll k = idx[b[i]];
        k = (k-i+n)%n; // number of right shift need to do to match this value (b[i])
        mp[k]++;
    }
    ll ans = INT_MIN;
    for(auto &[k, v]: mp){
        ans = max(ans, v); // max frequency of numbers matches for same amount of shift
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}