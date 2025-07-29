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
    vector<vi> dp(n+1, vi(3));   // dp[i][j] = maximium working day till i th day if he do task 'j' on that day
    
    for(ll i = 1; i <= n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}); // maximum working day till i-1 th day (If he stay idle today)
        
        if(a[i] == 1 || a[i] == 3){  // if do task 1 (contest)
            dp[i][1] = max(dp[i-1][0], dp[i-1][2])+1; 
            // can do contest if he was idle or in gym in the previous day
        }
        
        if(a[i] == 2 || a[i] == 3){ // if do task 2 (gym)
            dp[i][2] = max(dp[i-1][0], dp[i-1][1])+1;  
            //can go to gym if he was idle of in contest in the previous day
        }
    }
    cout << n-max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    
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