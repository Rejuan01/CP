#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

const ll N = 2e5;
ll spf[N+1];

void init(){
    for(ll i = 1; i <= N; i++) spf[i] = i;
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i)
        for(ll j = i*i; j <= N; j += i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}

void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi dp(n+1, 0);                              // dp[i] = f({i}) = no of operation only for the number i
    for(ll i = k+1; i <= n; i++){
        ll x = i;
        dp[i] = 1e9;
        while(x != 1){
            ll d = spf[x];
            x /= d;
            dp[i] = min(dp[i], d*dp[i/d]+1);
        }
    }
    ll cnt = 0;
    for(auto it: a) cnt += dp[it];
    cout << cnt << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    init();
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}