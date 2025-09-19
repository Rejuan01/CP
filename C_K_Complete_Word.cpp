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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<bool> vis(n);
    ll ans = 0;
    for(ll i = 0; i <= (k-1)/2; i++){
        map<char, ll> mp;
        for(ll j = i; j < n; j += k){
            mp[s[j]]++;
            if(k-1-2*i) mp[s[j+k-1-2*i]]++;
        }
        ll x = 0, c = 0;
        for(auto &[ch, cc]: mp){
            c += cc; 
            x = max(x, cc);
        }
        ans += c-x;
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