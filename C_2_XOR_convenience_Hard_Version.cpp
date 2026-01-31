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
    for(ll i = 1; i <= n; i++) a[i] = i;
    for(ll i = 2; i < n; i += 2){
        swap(a[i], a[i+1]);
    }
    swap(a[1], a[n]);
    if(n&1){
        for(ll i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl; return;
    }
    ll x = n, c = 0;
    while(x >>= 1) c++;
    x = n;
    x ^= (1<<c);
    if(x == 0){
        cout << -1 << endl; return;
    }
    swap(a[1], a[x]);
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
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