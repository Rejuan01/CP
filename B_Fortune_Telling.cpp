#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl 
void solve(){
    ll n, x, y;
    cin >> n >> x >> y;
    ll c = 0;
    for(ll i = 0; i < n; i++){
        ll k; cin >> k;
        if(k&1) c++;
    }
    if(x&1) c++;
    if((c&1) == (y&1)) alice;
    else bob;
}
// x and x+3 has opposite parity
// addition and xor has same effect in the LSB
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