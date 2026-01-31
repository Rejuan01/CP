#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    ll n, x;
    cin >> n >> x;
    ll s = 0, mx = LONG_LONG_MIN;
    for(ll i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        s += (b-1)*a;        // Distance the frog can cover without any rollback (free pass)
        mx = max(mx, a*b-c); // with each rollback, how much distance it can go after the total free pass 
    }
    ll d = x-s;
    if(d <= 0) cout << 0 << endl;
    else if(mx <= 0) cout << -1 << endl;
    else cout << (d+mx-1)/mx << endl;
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