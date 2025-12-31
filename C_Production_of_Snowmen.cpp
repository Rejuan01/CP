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
    vi a(n), b(n), c(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++) cin >> c[i];
    ll c1 = 0, c2 = 0;
    for(ll i = 0; i < n; i++){
        ll cnt = 0;
        for(ll j = 0; j < n; j++){
            // cout << i << " " << (i+j)%n << endl;
            // cout << a[j] << " " << b[(i+j)%n] << endl;
            if(a[j] < b[(i+j)%n]) cnt++;
            // else break;
        }
        if(cnt == n) c1++;
    }
    for(ll i = 0; i < n; i++){
        ll cnt = 0;
        for(ll j = 0; j < n; j++){
            if(b[j] < c[(i+j)%n]) cnt++;
            else break;
        }
        if(cnt == n) c2++;
    }
    cout << c1*c2*n << endl;
    
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