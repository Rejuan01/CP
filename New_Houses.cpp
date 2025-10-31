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
    ll n, m;
    cin >> n >> m;
    vi a;
    ll s = 0;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        s += x;
        // if(y-x >= 0) 
        a.pb(y-x);
    }
    if(n == 1){
        cout << s+a[0] << endl;
        return;
    }
    ssort(a);
    ll c = m-n; // no of empty spaces;
    while(c > 0 && a.size() > 0 && a.back() >= 0){
        // cout << a.size() << endl;
        if(a.size() == 2){
            // cout << a[0] << " " << a[1] << endl;
            if(a[0]+a[1] > 0){
                s += a[0]+a[1];
            }
            break;
        }
        s += a.back();
        a.pop_back();
        c--;
    }
    cout << s << endl;
    
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