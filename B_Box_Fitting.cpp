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
    ll n, w;
    cin >> n >> w;
    multiset<ll> ms;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        ms.insert(temp);
    }
    ll ans = 0;
    while(!ms.empty()){
        ll d = w;
        ans++;
        while(1){
            auto it = ms.upper_bound(d);
            if(it == ms.begin()) break;
            --it;
            d -= *it;
            ms.erase(it);
        }
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