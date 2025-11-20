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
    ll n;
    cin >> n;
    vi a(n), b(n);
    ll x = 0, y = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        x = x^a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
        y = y^b[i];
    }
    for(ll i = 0; i < n; i++){
        if(a[i] == b[i]) continue;
        ll k = a[i]^b[i];
        if((i&1)){
            if(y-x < (y^k)-(x^k)){
                y = y^k;
                x = x^k;
            }
        }
        else{
            if(x-y < (x^k)-(y^k)){
                y = y^k;
                x = x^k;
            }
        }
    }
    if(x == y) cout << "Tie" << endl;
    else if(x > y) cout << "Ajisai" << endl;
    else cout << "Mai" << endl;
    
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