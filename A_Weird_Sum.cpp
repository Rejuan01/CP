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
    map<ll, pair<vi, vi>>  mp;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            ll k; cin >> k;
            mp[k].first.push_back(j);
            mp[k].second.push_back(i);
        }
    }
    ll ans = 0;
    for(auto &[v, p]: mp){
        auto &[x, y] = p;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll s1 = 0, s2 = 0, s = 0;
        for(ll i = 1; i < x.size(); i++){
            ll d = x[i]-x[i-1];
            s += d*i;   // sum of difference between i th element with all previous element
            s1 += s;
        }
        s = 0;
        for(ll i = 1; i < y.size(); i++){
            ll d = y[i]-y[i-1];
            s += d*i;   
            s2 += s;
        }
        ans += s1+s2;
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}