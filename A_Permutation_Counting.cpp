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
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x; mp[x]++;
    }
    for(auto it = mp.begin(); it != prev(mp.end());){
        ll x = it->second;
        ll y = next(it)->first - it->first;
        if(k >= x*y){
            it = mp.erase(it);
            it->second += x;
            k -= x*y;
        }else{
            ll c = k/x;
            c += it->first;
            ll ans = c + (n-1)*(c-1);
            ll r = k%x;
            r = it->second - r;
            r = n-r;
            ans += r;
            cout << ans << endl;
            return;
        }
    }
    auto it = mp.begin();
    ll c = k/n;
    c += it->first;
    ll ans = c + (n-1)*(c-1);
    ans += k%n;
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