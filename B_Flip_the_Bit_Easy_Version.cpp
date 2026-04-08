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
void solve(ll tc){
    ll n, k, id;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    cin >> id;
    id--;
    ll p = id-1;
    ll x = 0, y = 0;
    while(p >= 0){
        if(a[p] != a[p+1]) x++;
        p--;
    }
    p = id+1;
    while(p < n){
        if(a[p] != a[p-1]) y++;
        p++;
    }
    k = a[id];
    if(a[0] == k) x--;
    if(a[n-1] == k) y--;
    x = max(x, y);
    if(x&1) x++;
    cout << x << endl;
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