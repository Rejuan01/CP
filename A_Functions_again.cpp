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
    ll n;
    cin >> n;
    vi a(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1) a[i-1] = abs(a[i-1]-a[i]);
    }
    a.pop_back();
    vi b = a;
    for(ll i = 1; i < n; i++){
        if(i&1) b[i] *= (-1LL);
        else a[i] *= (-1LL);
    } 
    ll mx = -1e18, s = 0;
    for(ll i = 1; i < n; i++){         // any subarray starts from odd idx 
        if(i&1) s = max(s+a[i], a[i]); 
        else s += a[i];                // Dont starts from even idx
        mx = max(mx, s);
    }
    s = 0;
    for(ll i = 2; i < n; i++){        // starts from even idx
        if(i&1) s += b[i];
        else s = max(s+b[i], b[i]);
        mx = max(mx, s);
    }
    cout << mx << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}