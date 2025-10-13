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
ll interact(vi &v){
    cout << "? " << v.size() << " ";
    for(auto &it: v) cout << it << " ";
    cout << endl;
    cout.flush();
    ll x; cin >> x;
    return x;
}
void solve(){
    ll n;
    cin >> n;
    vi a(2*n+1), b, c;
    b.pb(1);
    for(ll i = 2; i <= 2*n; i++){
        b.pb(i);
        ll x = interact(b);
        if(x != 0){
            a[i] = x;
            c.pb(i);
            b.pop_back();
        }
    }
    for(auto &i: b){
        c.pb(i);
        ll x = interact(c);
        a[i] = x;
        c.pop_back();
    }

    cout << "! ";
    for(ll i = 1; i <= 2*n; i++){
        cout << a[i] << " ";
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