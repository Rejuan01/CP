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
    vi k(n), c(m);
    for(ll i = 0; i < n; i++) cin >> k[i];
    for(ll i = 0; i < m; i++) cin >> c[i];
    sort(k.begin(), k.end(), greater<ll>());
    ll i = 0;
    ll ans = 0;
    while(i < n && i < k[i]){
        ans += c[i];
        i++;
    }
    while(i < n){
        ans += c[k[i]-1];
        i++;
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