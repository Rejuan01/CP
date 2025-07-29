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
void solve(){
    ll n;
    cin >> n;
    ll m = 0;
    vi c(1e5+5), DP(1e5+5); // DP[i] = result for numbers 0 to i
    for(ll i = 0; i < n; i++){
        ll v; cin >> v; 
        c[v]++;
        m = max(m, v);
    }
    DP[1] = c[1];
    for(ll i = 2; i <= m; i++){
        DP[i] = max(DP[i-1], i*c[i]+DP[i-2]); // max betwen taking and not taking i
    }
    cout << DP[m] << endl;
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