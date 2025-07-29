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
    ll n, k;
    cin >> n >> k;
    map<ll, ll, greater<ll>> mp;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        x = (k - x%k)%k; 
        if(x) mp[x]++;
    }
    if(mp.size() == 0){
        cout << 0 << endl; return;
    }
    ll x = 0, y = LONG_LONG_MIN;
    for(auto &[a, b]: mp){
        if(b > y){
            x = a, y = b;
        }
    }
    ll ans = k*y - (k-1-x);
    cout << ans << endl;
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