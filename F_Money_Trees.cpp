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
    vi a(n), h(n), s(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        s[i] = sum;
    }
    for(ll i = 0; i < n; i++) cin >> h[i];
    vp v; // [l, r] the ranges satisfy the condition of h
    for(ll i = 0; i < n; ){
        ll j = i;
        for(; j < n-1 && (h[j]%h[j+1] == 0); j++);
        v.push_back({i, j});
        i = j+1;
    }
    ll l = 0, r = n+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll flag = false;
        for(auto &it: v){ // for each ranges
            if(it.second-it.first+1 < m) continue; // len of range < m
            ll p = it.first, q = it.first+m-1; // sliding windiw
            while(q <= it.second){
                ll x = s[q]-s[p]+a[p]; // collected fruits
                if(x <= k){ 
                    flag = true; // current m can be the answer
                    break;
                }
                p++; q++;
            }
            if(flag) break;
        }
        if(flag){
            l = m;
        }else{
            r = m;
        }
    }
    cout << l << endl;
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