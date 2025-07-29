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
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        mp[x]++;
    }
    vi a;
    ll s = 0;
    for(auto &[k, v]: mp){
        a.push_back(v);
        s += v;
    }
    sort(a.begin(), a.end());
    ll s1 = s-a.back();
    if(a.back() > s1){
        cout << a.back()-s1 << endl; return;
    }
    if(s%2){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
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