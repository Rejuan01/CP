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
ll MOD = 1e9+7;
ll modpow(ll a, ll b, ll mod = MOD){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1){
            ans = (ans*a)%mod;
            b--; continue;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
    ll a, b, p;
    cin >> a >> b >> p;
    ll x = modpow(b, p-2, p); // modinv(b)
    cout << (a*x)%p << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}