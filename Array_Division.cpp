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
bool check(vi &a, ll k, ll m){
    ll cnt = 1, s = 0, n = a.size();
    for(ll i = 0; i < n; i++){
        if(a[i] > m) return 0;
        if(s+a[i] <= m) s += a[i];
        else{
            s = a[i];
            cnt++;
        }
    }
    return cnt <= k; // if lower no of split is possible, then k split is also possible
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 1e18;
    while(l+1 < r){
        ll m = (l+r)/2;
        if(check(a, k, m)){
            r = m;
        }else l = m;
    }
    cout << r << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}