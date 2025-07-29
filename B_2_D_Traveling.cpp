#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; i++){
        ll temp1, temp2;
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    if(a <= k && b <= k){
        cout << 0 << endl; return;
    }
    ll cost = abs(v[b-1].first-v[a-1].first) + abs(v[b-1].second-v[a-1].second);
    if(k < 2){
        cout << cost << endl; return;
    }
    ll costA = LONG_LONG_MAX, costB = LONG_LONG_MAX;
    for(ll i = 0; i < k; i++){
        if(a > k){
            ll ca = abs(v[i].first-v[a-1].first)+abs(v[i].second-v[a-1].second);
            costA = min(costA, ca);
        }
        if(b > k){
            ll cb = abs(v[i].first-v[b-1].first)+abs(v[i].second-v[b-1].second);
            costB = min(costB, cb);
        }
    }
    ll cost2 = 0;
    if(a > k) cost2 += costA;
    if(b > k) cost2 += costB;
    cout << min(cost, cost2) << endl;
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