#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    map<ll, ll> mp;
    for(ll i = 2; i*i <= n; i++){
        while(n%i == 0){
            n /= i;
            mp[i]++;
        }
    }
    if(n > 1) mp[n]++;
    ll ans = 0;
    for(auto &p: mp){
        ll e = p.second;
        ll i = 1;
        while(i <= e){
            e -= i;
            i++;
            ans++;
        }
    }
    cout << ans << endl;
}
// atcoder
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}