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
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    ssort(b);
    ll k = b[n/2];   // median of the full array
    vi dp(n+1);      // no of valid splits in [1, i]
    ll p = 0, q = 0;
    for(ll i = 1; i <= n; i++){
        if(a[i-1] < k) p--;
        else if(a[i-1] > k) p++;
        else q++;                       // no of k in [1, i]
        if(abs(p) >= q) continue;       // k isn't the median in [1, i]
        ll c = 0, x = 0;
        for(ll j = i-1; j >= 0; j--){
            if(a[j] < k) c--;
            else if(a[j] > k) c++;
            else x++;
            if(((i-j)&1) && abs(c) < x){ 
                // cout << j+1 << " " << i << endl; 
                 dp[i] = max(dp[i], dp[j]+1); 
            }
        }
    }
    cout << dp[n] << endl; 
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