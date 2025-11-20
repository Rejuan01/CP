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
    vi a(n);
    vi id(n+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        id[a[i]] = i;
    }
    vector<bool> c(n+1);
    vp v;
    ll k = -1;
    for(ll i = 0; i < n; i++){
        if(c[a[i]])continue;
        if(i != 0 && id[a[i]] > k){
            cout << "No" << endl;
            return;
        }
        for(ll x = a[i]; x <= n; x++){
            k = max(k, id[x]);
            if(c[x]) break;
            if(x != a[i]) v.pb({x, a[i]});
            else if(v.size()) v.pb({a[k], x});
            c[x] = 1;
        }
    }
    cout << "Yes" << endl;
    for(auto &[x, y]: v) cout << x << " " << y << endl;
    
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