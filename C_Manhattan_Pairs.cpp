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
    vector<tuple<ll, ll, ll>> v, a, b;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y, i+1});
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < n/2; i++){
        a.push_back({get<1>(v[i]), get<0>(v[i]), get<2>(v[i])});
    }
    for(ll i = 0; i < n/2; i++){
        b.push_back({-get<1>(v[n/2+i]), get<0>(v[n/2+i]), get<2>(v[n/2+i])});
    }
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());
    for(ll i = 0; i < n/2; i++){
        cout << get<2>(a[i]) << " " << get<2>(b[i]) << endl;
    }
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