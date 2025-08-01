#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(){
    ll n;
    cin >> n;
    map<ll, ll> mp;
    map<pr, ll> idx;
    for(ll i = 1; i <= n; i++){
        ll x, y;
        cin >> x >> y;
        mp[x] = max(mp[x], y);
        idx[{x, y}] = i;
    }
    cout << mp.size() << endl;
    for(auto &[x, y]: mp){
        cout << idx[{x, y}] << " ";
    } cout << endl;
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