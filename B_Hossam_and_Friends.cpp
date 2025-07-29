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
    ll n, m;
    cin >> n >> m;
    map<ll, set<ll, greater<ll>>> mp;
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y; if(x < y) swap(x, y);
        mp[x].insert(y);
    }
    ll ans = 0, s = 0;
    for(ll i = 1; i <= n; i++){
        if(mp.find(i) == mp.end()){ // i has friendship with all < i
            s++; 
            ans += s;
            continue;
        }
        ll x = *mp[i].begin(); // max index who is not friend 
        if(x < i-s){
            s++; 
            ans += s;
            continue;
        }
        s = i-x;
        ans += s;
    }
    cout << ans << endl;
    
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