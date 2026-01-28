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
bool check(vi &a, vi &b, double m, ll k){   // if there is k elements for which sum(a[i]) >= m*sum(b[i]). So sum(a[i] - m*b[i]) >= 0
    ll n = a.size();
    vector<double> c(n);
    for(ll i = 0; i < n; i++) c[i] = a[i]-m*b[i];
    rsort(c);
    double s = 0;
    for(ll i = 0; i < k; i++) s += c[i]; 
    return s >= 0;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i] >> b[i];
    double l = 1e-6, r = 1e10+1; 
    while(l+1e-6 < r){               // find the max ratio
        double m = (l+r)/2;
        if(check(a, b, m, k)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(7) << l << endl;
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