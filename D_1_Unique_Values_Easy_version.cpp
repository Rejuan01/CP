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
ll query(ll x, ll y){
    cout << "? " << (y-x+1) << " ";
    for(ll i = x; i <= y; i++) cout << i << " ";
    cout << endl;
    cout.flush();
    ll c;
    cin >> c;
    return c;
}
ll query1(ll x, ll y, ll z){
    cout << "? " << (y-x+2) << " ";
    for(ll i = x; i <= y; i++) cout << i << " ";
    cout << z << " ";
    cout << endl;
    cout.flush();
    ll c;
    cin >> c;
    return c;
}
void solve(ll tc){
    ll n;
    cin >> n;
    ll x, y, z;
    ll l = 0, r = 2*n+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll k = query(1, m);
        if((m-k)&1) r = m;
        else l = m;
    }
    z = r;      // last idx
    l = 1, r++;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll k = query(m, z);
        if((z-m+1-k)&1) l = m;
        else r = m;
    }
    x = l;      // first idx
    r = z-1;
    while(l+1 < r){
        ll m = (l+r)/2;
        ll k = query1(x, m, z);
        if((m-x+2-k)&1) r = m;
        else l = m;
    }
    y = r;      // second idx
    cout << "! " << x << " " << y << " " << z << endl;
    cout.flush();
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