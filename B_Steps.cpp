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
    ll n, m, x, y, z;
    cin >> n >> m >> x >> y >> z;
    ll ans = 0;
    for(ll i = 0; i < z; i++){
        ll a, b;
        cin >> a >> b;
        ll p, q; // max steps towards x and y axis
        if(a == 0) p = LONG_LONG_MAX;
        else if(a > 0) p = (n-x)/a;
        else p = (-1)*(x-1)/a;

        if(b == 0) q = LONG_LONG_MAX;
        else if(b > 0) q = (m-y)/b;
        else q = (-1)*(y-1)/b;
        p = min(p, q);
        x += p*a;
        y += p*b;
        ans += p;
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