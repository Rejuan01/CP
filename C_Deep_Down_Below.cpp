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
    vp v;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        ll m = 0;
        for(ll j = 0; j < k; j++){
            ll x; 
            cin >> x;
            x += 1-j; // min power need to enter with to beat current monstar
            m = max(m, x);
        }
        v.push_back({m, k}); // min power, monstar count
    }
    sort(v.begin(), v.end());
    ll l = 1, r = 1e9+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll x = m;
        bool flag = false;
        for(auto &it: v){
            if(x < it.first){
                flag = true;
                break;
            }
            x += it.second;
        }
        if(flag){
            l = m;
        } else r = m;
    }
    cout << r << endl;
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