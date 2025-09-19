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
    map<ll, vi, greater<ll>> mp;
    for(ll i = 1; i <= n; i++){
        cout << "? " << i << " " << n << " ";
        for(ll j = 1; j <= n; j++) cout << j << " ";
        cout << endl;
        cout.flush();
        ll x;
        cin >> x;
        mp[x].pb(i);
    }
    vi a;
    ll x = mp.begin()->second.front();
    ll s = mp.begin()->first;
    a.pb(x);
    while(a.size() < s){
        ll c = s-a.size();
        // cout << a.back() << " " << a.size() << " " << c << " " << s << endl;
        vi &v = mp[c];
        for(auto &p : v){
            cout << "? " << a.back() << " " << 2 << " " << p << " " << a.back() << endl;
            ll y; cin >> y;
            if(y == 2){
                a.pb(p);
                break;
            }
        }
    }
    cout << "! " << s << " ";
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