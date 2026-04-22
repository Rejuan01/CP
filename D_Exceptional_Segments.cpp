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
const ll mod = 998244353;
ll cal(ll x){               // no of points where prefix xor = 1 in [1, x]
    if(x < 1) return 0;
    return (x-1)/4 + 1;
}
ll cal3(ll x){              // no of points where prefix xor = 0 in [1, x]
    if(x < 3) return 0;
    return (x-3)/4 + 1;
}
void solve(ll tc){
    ll n, x;
    cin >> n >> x;
    ll a = cal(x-1), b = cal(n)-cal(x-1);
    a %= mod;
    b %= mod;
    ll k1 = (a*b)%mod;
    a = cal3(x-1), b = cal3(n)-cal3(x-1);
    a++;                                    // empty prefix has also xor = 0
    a %= mod;
    b %= mod;
    ll k2 = (a*b)%mod;
    cout << (k1+k2)%mod << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}