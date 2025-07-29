#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll countBits(ll x){
    ll count = 0;
    while(x){
        count++;
        x >>= 1;
    }
    return count;
}
void solve(){
    ll m;
    cin >> m;
    map<ll, ll> mp;
    while(m--){
        ll t, v;
        cin >> t >> v;
        if(t == 1){
            mp[v]++; 
            continue;
        }
        for(ll i = countBits(v)-1; i >= 0; i--){
            if(mp.find(i) == mp.end()) continue;
            ll x = 1 << i;
            ll y = min(mp[i], v/x);
            v -= y*x;
            if(v == 0) break;
        }
        if(v == 0) yes;
        else no;
    }
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