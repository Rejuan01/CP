#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    string s; cin >> s;
    vi c(n+1);
    ll a = 0, b = 0;
    for(ll i = 1; i <= n; i++){
        if(s[i-1] == 'a') a++;
        else b++;
        c[i] = b-a;
    }
    if(a == b){
        cout << 0 << endl; return;
    }
    ll ans = 1e9, k = b-a;
    map<ll,ll> mp;        // stores the idx of a specific diff between 'b' count and 'a' count
    mp[0] = 0;
    for(ll i = 1; i <= n; i++){
        ll x = c[i]-k;
        if(mp.count(x)){
            ll d = i-mp[x];
            ans = min(ans, d);
        }
        mp[c[i]] = i;
    }
    if(ans == n) ans = -1;
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