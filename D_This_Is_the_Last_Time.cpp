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
    map<ll, vp> mp;
    for(ll i = 0; i < n; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        if(z <= k) continue;
        mp[z].push_back({x, y});
    }
    for(auto &[p, v]: mp){
        bool flag = false;
        for(auto &[x, y]: v){
            if(x <= k && k <= y){
                flag = true;
                break;
            }
        }
        if(flag){
            k = p;
        }
    }
    cout << k << endl;
    
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