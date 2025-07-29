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
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll temp; 
        cin >> temp;
        mp[temp]++;
    }
    vp v;
    for(auto &it: mp){
        v.push_back(it);
    } 
    ll ans = 0;
    for(ll i = 0; i < v.size(); ){
        ll j = i;
        while(j < v.size()-1 && v[j+1].first==v[j].first+1) j++;
        ll s = 0;
        for(ll p = i; p < i+k && p <= j; p++){
            s += v[p].second;
        }
        ans = max(ans, s);
        ll p = i, q = i+k-1; // sliding window
        while(q < j){
            s += v[q+1].second-v[p].second;
            p++; q++;
            ans = max(ans, s);
        }
        i = j+1;
    }
    cout << ans << endl;
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