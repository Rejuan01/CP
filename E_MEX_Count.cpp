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
    ll n;
    cin >> n;
    vi a(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll p = 0;
    ll mx = mp.rbegin()->first+1;
    for(auto &[k, v]: mp){
        if(k != p){
            mx = p;
            break;
        }
        p++;
    }
    if(mx == 0){
        for(ll i = 0; i <= n; i++){
            cout << 0 << " ";
        } cout << endl;
        return;
    }
    ll c = mp[0];
    for(ll i = 0; i < c; i++){
        cout << mx << " ";
    }
    for(ll i = c; i <= n; i++){
        cout << 0 << " ";
    }
    cout << endl;
    
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