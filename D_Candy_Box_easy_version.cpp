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
    map<ll, ll> m1;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        m1[x]++;
    }
    vi a;
    for(auto &[k, v]: m1){
        a.push_back(v);
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0, x = a[0];
    for(auto it: a){
        if(it >= x){
            ans += x;
            x--;
        }else{
            ans += it;
            x = it-1;
        }
        if(x == 0) break;
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