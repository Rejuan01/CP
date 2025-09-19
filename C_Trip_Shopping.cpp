#include<bits/stdc++.h>
using namespace std;
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
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    vp v;
    for(ll i = 0; i < n; i++){
        if(a[i] < b[i]) swap(a[i], b[i]);
        v.push_back({a[i], b[i]});
        mp[b[i]]++;
        ans += a[i]-b[i];
    }
    sort(v.begin(), v.end());
    ll d = LONG_MAX;
    for(auto &[p, q]: v){
        mp[q]--;
        if(mp[q] == 0) mp.erase(q);
        if(mp.begin() != mp.end() && mp.begin()->first <= p){
            cout << ans << endl;
            return;
        }
        if(mp.begin() != mp.end()) d = min(d, mp.begin()->first-p);
    }
    cout << ans+2*d << endl;
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