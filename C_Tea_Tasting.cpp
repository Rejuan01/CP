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
    ll n;
    cin >> n;
    vi a(n+1), b(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
        b[i] += b[i-1];
    }
    vi ans(n+1), c(n+2);
    //pbds st;
    for(ll i = 1; i <= n; i++){
        ll idx = upper_bound(b.begin(), b.end(), a[i]+b[i-1]) - b.begin();
        if(idx != n+1){
            ans[idx] += a[i]-(b[idx-1]-b[i-1]);
        }
        c[i]++;
        c[idx]--;
    }
    for(ll i = 1; i <= n; i++){
        c[i] += c[i-1];
        ans[i] += c[i]*(b[i]-b[i-1]);
        cout << ans[i] << " ";
    } cout << endl;
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