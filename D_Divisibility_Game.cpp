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
    ll n, m;
    cin >> n >> m;

    vi a(n), b(m), c(n+m+1), d(n+m+1);

    for(ll i = 0; i < n; i++){
        cin >> a[i];
        d[a[i]]++;
    }
    for(ll i = 0; i < m; i++) cin >> b[i];

    for(ll k = 1; k <= n+m; k++){
        if(d[k])
        for(ll i = k; i <= n+m; i += k){
            c[i] += d[k];  
        }
    }
    ll x = 0, y = 0, z = 0;

    for(auto it: b){
        if(c[it] == n) x++;       // only alice can remove
        else if(!c[it]) y++;      // only bob can remove
        else z++;                 // both can remove
    }

    if(x + (z&1) > y) cout << "Alice" << endl;
    else cout << "Bob" << endl;

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