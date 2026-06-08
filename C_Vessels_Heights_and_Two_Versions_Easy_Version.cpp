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
    vi h(n);
    for(ll i = 0; i < n; i++) cin >> h[i];
    for(ll i = 0; i < n; i++){
        vi w(n);
        ll s = 0;
        w[i] = 0;
        ll cnt = 0;
        // cout << i << "** " << endl;
        for(ll j = (i+1)%n; j != i; j = (j+1)%n){
            ll id = (j-1+n)%n;
            w[j] = max(w[id], h[id]);
        }
        // for(auto it: w) cout << it << " ";
        // cout << endl;
        for(ll j = (i-1+n)%n; j != i; j = (j-1+n)%n){
            ll k = max(w[(j+1)%n], h[j]);
            w[j] = min(w[j], k);
            s += w[j];
        }
        // for(auto it: w) cout << it << " ";
        // cout << endl;
        cout << s << " ";
    }
    cout << endl;
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