#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    vector<ll> fact = {1};
    for(ll i = 1; i <= 14; i++){
        fact.push_back(fact.back() * i);
    }
    ll m = __builtin_popcountll(n);
    ll ans = m;
    for(ll i = 0; i < (1<<15); i++){ // all possible subset of factorials
        ll x = 0;
        for(ll j = 0; j < 15; j++){
            if(i&(1<<j)) x += fact[j];
        }
        if(x > n) continue;
        ll k = __builtin_popcountll(i) + __builtin_popcountll(n-x);
        ans = min(ans, k);
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