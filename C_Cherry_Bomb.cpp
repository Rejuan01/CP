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
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    set<ll> p;
    for(ll i = 0; i < n; i++){
        if(b[i] == -1) continue;
        p.insert(a[i]+b[i]);
    }
    if(p.size() > 1){
        cout << 0 << endl;
        return;
    }
    if(p.size() == 1){
        ll z = *p.begin();
        for(ll i = 0; i < n; i++){
            if(b[i] != -1) continue;
            ll x1 = z-a[i];
            if(x1 > k || x1 < 0){
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
        return;
    }
    ll x = LONG_LONG_MAX, y = LONG_LONG_MIN;
    for(auto it: a){
        x = min(x, it);
        y = max(y, it);
    }
    x += k;
    x -= y;
    cout << x+1 << endl;

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