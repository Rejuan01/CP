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
ll mod = 1e9 + 7;
vi dp(1e6+5, -1);
ll calc(ll x){
    if(x == 0){
        return 1;
    }
    if(dp[x] != -1) return dp[x];
    ll s = 0;
    ll p;
    for(ll i = 1; i <= 6 && x-i >= 0; i++){
        if(dp[x-i] != -1) s += dp[x-i];
        else s += calc(x-i);
        s %= mod;
    }
    dp[x] = s;
    return dp[x];
}

void solve(){
    ll n;
    cin >> n;
    //cout << calc(n) << endl;
    vi DP(n+1);
    DP[0] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= 6 && i-j >= 0; j++){
            DP[i] += DP[i-j];
            DP[i] %= mod;
        }
    }
    cout << DP[n] << endl;
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