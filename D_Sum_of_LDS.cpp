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
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    vi dp(n+1); 
    // dp[i] = sum of 'LDS lengths' for all the contigeous subarrays end at a[i] (from all the previous elements of a[i])
    for(ll i = 1; i <= n; i++){
        if(a[i-1] < a[i]) dp[i] = dp[i-1]+1;
        else dp[i] = dp[i-1]+i;
    }  
    ll x = 0;
    for(auto it: dp) x += it;
    cout << x << endl;
    
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