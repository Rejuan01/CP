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
    map<ll, set<ll>> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        for(ll j = 1; j < 58; j++){
            ll x = 1LL<<j;
            mp[x].insert(a[i]%x); // remainder when divide by 2^j
        }
    } // answer can be 2, 4, 8, 16, ....
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second.size() == 2){
            cout << it->first << endl; return;
        }
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