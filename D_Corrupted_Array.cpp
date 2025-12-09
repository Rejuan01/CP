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
    vi b(n+2);
    for(ll i = 0; i < n+2; i++) cin >> b[i];
    ssort(b);
    ll s = 0;
    for(ll i = 0; i < n; i++) s += b[i];
    if(s == b[n] || s == b[n+1]){
        for(ll i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
        return;
    }
    s += b[n];
    s -= b[n+1];
    bool flag = 1;
    // cout << s << endl;
    for(ll i = 0; i <= n; i++){
        if(s == b[i]){
            b[i] = 0;
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << -1 << endl; return;
    }
    for(ll i = 0; i <= n; i++){
        if(b[i]) cout << b[i] << " ";
    }
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