#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 

bool check(ll k, vi &v){
    ll n = v.size();
    vi c(21, 0);
    for(ll i = 0; i < k; i++){
        ll x = v[i];
        ll j = 0;
        while(x){
            c[j] += (x&1);
            j++;
            x >>= 1;
        }
    }
    ll p = 0, q = k-1;
    vi c1 = c;
    while(q < n-1){
        ll x = v[p];
        ll j = 0;
        while(x){
            c1[j] -= (x&1);
            j++;
            x >>= 1;
        }
        x = v[q+1];
        j = 0;
        while(x){
            c1[j] += (x&1);
            j++;
            x >>= 1;
        }
        for(ll i = 0; i < 21; i++){
            if(c[i] > 0 && c1[i] == 0) return false;
            if(c[i] == 0 && c1[i] > 0) return false;
        }
        p++; q++;
    }
    return true;
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = n;
    while(l+1 < r){
        ll m = (l+r)/2;
        if(check(m, a)){
            r = m;
        }else{
            l = m;
        }
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