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
    ll n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    map<pair<ll, ll>, ll> m; // <{a%x, a%y}, count>
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll X = (x-a[i]%x)%x;
        ll Y = a[i]%y;
        ans += m[{X, Y}]; // a[i] will pair with m[{X, Y}] numbers of elements(before a[i])
        m[{a[i]%x, a[i]%y}]++;
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