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
void solve(){
    ll x; cin >> x;
    ll y = x, n = 0;
    while(y){
        n++;
        y /= 10;
    }
    vi a;
    y = x;
    for(ll i = 1; i < n; i++){
        ll p = y/10, q = y%10;
        y = q*pow(10LL, n-1) + p;
        if(y <= x) continue;
        ll d = y-x;
        if(d%n == i){
            a.pb(d);
        }
    }
    cout << a.size() << endl;
    ssort(a);
    for(auto it: a){
        cout << it << " ";
    } cout << endl;
    
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