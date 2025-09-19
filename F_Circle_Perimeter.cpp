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
ll countPoint(ll rad){ // points under (<) the radius 'rad'
    ll c = 0;
    for(ll x = rad-1; x > 0; x--){
        ll l = 1, r = rad;
        while(l+1 < r){
            ll y = (l+r)/2;
            if(x*x + y*y < rad*rad) l = y;
            else r = y;
        }
        c += l;
    }
    c *= 4; // all quadrants
    c += 4*(rad-1)+1;  // points on the exis
    return c;
}
void solve(){
    ll r;
    cin >> r;
    ll ans = countPoint(r+1) - countPoint(r);
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