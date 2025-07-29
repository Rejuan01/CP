#include<bits/stdc++.h>
using namespace std;
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
ll n, x;
vi a;
// vi dp(1e6+10, -1); // dp[i] = min number of coins to get i money
// ll calc(ll x){
//     if(x < a[0]) return -2;
//     if(dp[x] != -1) return dp[x];
//     ll mn = LONG_LONG_MAX;
//     for(ll i = 0; i < n && x-a[i] >= 0; i++){
//         ll p = calc(x-a[i]);
//         if(p >= 0) mn = min(mn, p);
//     }
//     if(mn == LONG_LONG_MAX) dp[x] = -2;
//     else dp[x] = mn+1;
//     return dp[x];
// }
void solve(){
    cin >> n >> x;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        a.push_back(x);
        //dp[x] = 1;
    }
    sort(a.begin(), a.end());
    // if(calc(x) == -2){
    //     cout << -1 << endl;
    // }
    // else cout << calc(x) << endl;

    vi DP(x+1, -1); // DP[i] = minimum number of coins to get i money
    DP[0] = 0;
    for(ll i = 1; i <= x; i++){
        ll mn = 1e9;
        for(ll j = 0; j < n && i-a[j] >= 0; j++){
            if(DP[i-a[j]] == -1) continue;
            mn = min(mn, DP[i-a[j]]);
        }
        if(mn != 1e9) DP[i] = mn+1;
    }
    cout << DP[x] << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}