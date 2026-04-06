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
const ll mod = 676767677;
void solve(ll tc){
    ll n, m;
    cin >> n >> m;
    vi a(n), c(m);
    vi v[m];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]]++;
        v[a[i]].pb(i);
    }
    ll ans = 1, cnt = v[0].size();
    for(ll i = 1; i < m; i++){
        for(auto j: v[i]){
            ll mn = 1e9;                        // min time when neighour sit
            if(j-1 >= 0) mn = min(mn, a[j-1]);
            if(j+1 < n) mn = min(mn, a[j+1]);
            if(mn == i-1){                      // sit immediately after neighbour (i == mn+1)
                ans = (ans*cnt)%mod;
            }
            else if(mn < i) ans = (ans*v[i-1].size())%mod; // didn't sit immediately and waited for some (0ne or all) of the persons who sit in time i-1
            else{
                cout << 0 << endl;
                return;
            }
        }
        cnt += v[i].size();
    }
    cout << ans << endl;
    
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