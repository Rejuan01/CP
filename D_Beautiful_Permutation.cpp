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
ll query(ll x, ll l, ll r){
    cout << x << " " << l << " " << r << endl;
    ll s; cin >> s;
    return s;
}
void solve(){
    ll n;
    cin >> n;
    ll x = query(2, 1, n) - query(1, 1, n); // the len of modification
    ll l = 0, r = n+1;
    while(l+1 < r){       // The max no of elements from start till which no modification occured
        ll m = (l+r)/2;
        ll d = query(2, 1, m)-query(1, 1, m);
        if(d == 0) l = m;
        else r = m;
    }
    cout << "! " << l+1 << " " << l+x << endl;
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