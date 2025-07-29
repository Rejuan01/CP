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
    vi u(n);
    map<ll, vi> mp;
    for(ll i = 0; i < n; i++){
        cin >> u[i];
        mp[u[i]] = {0};
    }
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        ll v; cin >> v; sum += v;
        mp[u[i]].push_back(v);
    }
    vi ans(n);
    for(auto &[k, v]: mp){
        sort(v.begin(), v.end());
        for(ll i = 1; i < v.size(); i++){
            v[i] = v[i-1]+v[i];
        }
    }
    for(auto &[key, v]: mp){
        //cout << v.back() << endl;
        for(ll k = 1; k <= v.size(); k++){
            ll l = (v.size()-1) % k;
            ans[k-1] += v.back()-v[l];
            //cout << k << " " << v[l] << endl;
        }
    }
    for(auto i: ans){
        cout << i << " ";
    }
    cout << endl;

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