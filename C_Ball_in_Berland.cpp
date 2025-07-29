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
    ll aa, bb, k;
    cin >> aa >> bb >> k;
    vi a(k), b(k);
    for(ll i = 0; i < k; i++) cin >> a[i];
    for(ll i = 0; i < k; i++) cin >> b[i];
    map<ll, vi> mp;
    map<ll, ll> c;
    for(ll i = 0; i < k; i++){
        mp[a[i]].push_back(b[i]);
        c[b[i]]++;
    }
    ll ans = 0;
    for(auto it = mp.begin(); it != prev(mp.end()); ++it){
        auto &v = it->second;
        k -= v.size();   // remaining pairs
        for(auto it: v){
            c[it]--;
            ans += k-c[it];
        }
    }
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