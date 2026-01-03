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
    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vi s(n+1);
    s[1] = x;
    for(ll i = 2; i <= n; i++){
        s[i] = (s[i-1]*a+b)%c;
    }
    for(ll i = 1; i <= n; i++) s[i]^= s[i-1];
    ll l = 0, r = k;
    ll ans = 0;
    while(r <= n){
        ll val = s[r]^s[l];
        ans ^= val;
        l++; r++;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}