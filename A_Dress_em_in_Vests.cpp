#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll q = 1e10;
void solve(){
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vi a(n), b(m);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
    vp ans;
    for(ll i = 0; i < n; i++){
        ll index = lower_bound(b.begin(), b.end(), a[i]-x) - b.begin();
        if(index == m) break;
        if(b[index] > a[i]+y) continue;
        ans.push_back({i+1, index+1});
        b[index] -= q; // later a[i]s will not colflict here ;)
    }
    cout << ans.size() << endl;
    for(auto &it: ans){
        cout << it.first << " " << it.second << endl;
    }
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