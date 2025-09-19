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
    ll n, m, q;
    cin >> n >> m >> q;
    vi a(n), b(m), s1(n+1), s2(m+1);

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    for(ll i = 1; i <= n; i++) s1[i] = s1[i-1]+a[i-1];
    for(ll i = 1; i <= m; i++) s2[i] = s2[i-1]+b[i-1];
    
    while(q--){
        ll x, y, z; cin >> x >> y >> z;
        ll l = z-min(x, z), r = min(z, y)+1;
        while(l+1 < r){
            ll mid = (l+r)/2;
            if(b[mid-1] > a[z-mid]) l = mid;
            else r = mid;
        }
        cout << s2[l] + s1[z-l] << endl;
    }
}

// taking max possible to take from a and minimum from b. Till the lowest taken from a is smaller than highest 'not taken' from b, take from b and discard from a
// in sorted a and b I need to find maximum index i in b such that z-i+1 th value (next to the corresponding value) in a is smaller than it

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