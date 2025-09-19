#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
    ll a, b;
    cin >> a >> b;
    vector<vi> dp(a+1, vi(b+1)); // min no of squares required to form a ixj rectangle
    for(ll i = 1; i <= a; i++){
        for(ll j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 1; continue;
            }
            ll m = 1e9;
            for(ll k = 1; k <= j/2; k++){
                m = min(m, dp[i][k]+dp[i][j-k]);
            }
            for(ll k = 1; k <= i/2; k++){
                m = min(m, dp[k][j]+dp[i-k][j]);
            }
            dp[i][j] = m;
        }
    }
    cout << dp[a][b]-1 << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}