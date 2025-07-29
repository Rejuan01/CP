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
    map<ll, ll, greater<ll>> mp;
    ll a[n][m] = {0};
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    ll s = mp.begin()->second;
    ll mx = mp.begin()->first;
    vi r(n), c(m);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(a[i][j] == mx){
                r[i]++;
                c[j]++;
            }
        }
    }
    ll p = -1, q = -1;
    bool flag = false;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll x = r[i]+c[j];
            if(a[i][j] == mx) x--;
            if(x == s){
                p = i, q = j; flag = true; break;
            }
        } if(flag) break;
    }
    if(!flag){
        cout << mx << endl; return;
    }
    mx = LONG_LONG_MIN;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(i == p || j == q){
                a[i][j]--;
            }
            mx = max(mx, a[i][j]);
        }
    }
    cout << mx << endl;
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