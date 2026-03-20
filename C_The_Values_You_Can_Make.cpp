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
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n+1);
    vector<vector<bool>> dp(n+1, vector<bool>(k+1));
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ssort(a);
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        dp[i][0] = 1;
        for(ll j = 1; j <= k; j++){                // if having sum=j wth first i elements is possible
            if(dp[i-1][j]) dp[i][j] = 1;
            else if(j >= a[i] && dp[i-1][j-a[i]]) dp[i][j] = 1;
        }
    }
    if(!dp[n][k]){
        cout << 0 << endl; return;
    }
    queue<pr> q;
    vi b;
    q.push({n, k});
    while(!q.empty()){
        ll i = q.front().first, j = q.front().second;
        q.pop();
        if(i && dp[i-1][j]) q.push({i-1, j});
        if(i && j >= a[i] && dp[i-1][j-a[i]]){
            q.push({i-1, j-a[i]});
            b.pb(a[i]);
        }
    }
    vi ans;
    set<ll> st;
    ans.pb(0);
    st.insert(0);
    for(ll i = 0; i < b.size(); i++){
        ll x = ans.size();
        for(ll j = 0; j < x; j++){
            if(ans[j]+b[i] <= k){
                ans.pb(ans[j]+b[i]);
                st.insert({ans[j]+b[i]});
            }
        }
    }
    cout << st.size() << endl;
    for(auto it: st) cout << it << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}