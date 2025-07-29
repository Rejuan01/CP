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
    ll x = *min_element(a.begin(), a.end());
    ll y = *max_element(a.begin(), a.end());
    if(x == y){
        ll k = mp[x];
        cout << 0 << " " << k*(k-1)/2 << endl; return;
    }
    cout << y-x << " " << mp[x]*mp[y] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}