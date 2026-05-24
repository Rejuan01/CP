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
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    ll l = 1, r = 2*n+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll good = 0, bad = 0;
        bool flag = 0;                  // if the previous one was bad
        for(ll i = 0; i < n; i++){
            if(min(a[i], b[i]) >= m){
                good++;
                flag = 0;
            }
            else if(max(a[i], b[i]) < m && !flag){       // consequitive bads are marged and counted once
                bad++;
                flag = 1;
            }
        }
        if(good > bad) l = m;  // overall merge would be good
        else r = m;
    }
    cout << l << endl;
}
// neutrals (one greater or equal and other is less) have no effect in merge
// neutral+good= good, neutral+bad = bad.
// good + bad = neutral. So there must be overall good > bad
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