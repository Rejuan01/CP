#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N = 1e6+2;
//vi a(N);
ll c[10][N+1];
ll f(ll n){
    ll ans = 1;
    ll x = n;
    while(x){
        if(x%10 != 0)
            ans *= (x%10);
        x/=10;
    }
    return ans;
}
ll g(ll n){
    if(n < 10) return n;
    else return g(f(n));
}
void solve(){
    ll l, r, k;
    cin >> l >> r >> k;
    ll s = 0;
    ll x = c[k][r] - c[k][l-1];
    cout << x << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(ll i = 1; i <= N; i++){
        ll p = g(i);
        for(ll j = 1; j < 10; j++)
            c[j][i] = c[j][i-1];
        c[p][i]++;
        //a[i] = p;
    }
    while(t--){
       solve();
    }
    return 0;
}