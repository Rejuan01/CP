#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll mod = 998244353;
ll pow_mod(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n+1), b(n+1);
    vi p(n+1), q(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i-1];
        if(a[p[i]] <= a[i]){
            p[i] = i;
        }
        //cout << p[i] << " ";
    } //cout << endl;
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
        q[i] = q[i-1];
        if(b[q[i]] <= b[i]){
            q[i] = i;
        }//cout << q[i] << " ";
    } //cout << endl;
    vi r;
    for(ll i = 1; i <= n; i++){
        ll x = a[p[i]], y = b[q[i]];
        if(x > y){
            ll k = i-p[i]+1;
            ll z = (pow_mod(2, x) + pow_mod(2, b[k]))%mod;
            r.push_back(z); continue;
        }
        if(x < y){
            ll k = i-q[i]+1;
            ll z = (pow_mod(2, y) + pow_mod(2, a[k]))%mod;
            r.push_back(z); continue;
        }
        ll k1 = i-p[i]+1, k2 = i-q[i]+1; 
        ll k = max(a[k2], b[k1]);
        ll z = (pow_mod(2, x) + pow_mod(2, k))%mod;
        r.push_back(z);
    }
    for(auto it: r){
        cout << it << " ";
    } cout << endl;

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