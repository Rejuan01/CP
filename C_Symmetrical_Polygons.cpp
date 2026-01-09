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
    vi a(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vi b;
    ll s = 0;
    ll cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(it->second & 1){
            b.pb(it->first);
            it->second--;
        }
        s += (it->first)*(it->second);
        if(it->second) cnt += it->second;
    }
    rsort(b);
    ll ans = s;
    for(auto it: b){
        if(it < s){
            ans += it;
            break;
        }
    }
    for(ll i = 0; i+1 < b.size(); i++){
        if(s+b[i+1] > b[i]){
            ans = max(ans, s+b[i]+b[i+1]); break;
        }
    }
    if(ans == s && cnt < 3) ans = 0;
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