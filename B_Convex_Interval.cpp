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
ll cross(pr p1, pr p2, pr p3) {
    return (p2.first - p1.first) * (p3.second - p1.second) - 
           (p2.second - p1.second) * (p3.first - p1.first);
}
void solve(){
    ll n;
    cin >> n;
    vp a(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    ll l = 0, r = 0;
    while(r < n){
        if(r-l+1 < 3){
            r++; 
            continue;
        }
        ll k1 = cross(a[r-2], a[r-1], a[r]);
        ll k2 = cross(a[r-1], a[r], a[l]);
        ll k3 = cross(a[r], a[l], a[l+1]);

        if(k1 < 0 && k2 < 0 && k3 < 0){ // all in counter clockwise (new 3 angles are < 180)
            ans = max(ans, r-l+1);
            r++; // expand till valid
        }
        else l++; // shrink till a valid segment then later expand
    }
    cout << ans << endl;
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