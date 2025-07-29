#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define jr cout<<"Jerry"<<endl
#define tom cout<<"Tom"<<endl 
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    ll s = 0;
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        mp[a[i]]++;
    }
    auto x = *mp.begin(), y = *prev(mp.end());
    if(y.first - x.first - 1 > k){
        jr; return;
    }
    if(y.first - x.first - 1 == k && y.second > 1){
        jr; return;
    }
    if(s%2 == 0){
        jr;
    }else{
        tom;
    }
    
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