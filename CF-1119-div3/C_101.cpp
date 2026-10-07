#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 0;
    while(l < n && a[l] == 0) l++;
    r = l+1;
    ll x = -1, y = -1, k = 0;
    while(r < n){
        if(a[r] != 0){
            if(r-l+1 > k){
                k= r-l+1;
                x = l, y = r;
            }
            if(a[r] == 1){
                l = r;
            }
        }
        r++;
    }
    for(ll i = 0; i < n; i++){
        if(a[i] == -1 && i != x && i != y){
            if(k) a[i] = 0;
            else a[i] = 1;
        }
    }
    if(x >= 0) a[x] = 1;
    if(y >= 0) a[y] = 1;
    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
    } cout << endl;
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