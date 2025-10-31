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
    ll n;
    cin >> n;
    vi a(n), b(n), ans;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    stack<ll> stk;
    for(ll i = n-1; i >= 0; i--){
        while(!stk.empty() && a[stk.top()] >= a[i]) stk.pop();

        if(stk.empty()) ans.pb(i+1);
        else{
            ll idx = stk.top();
            if(b[i] > b[idx]) ans.pb(i+1);
        }
        stk.push(i);
    }
    cout << ans.size() << endl;
    rev(ans);
    for(auto &it: ans) cout << it << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}