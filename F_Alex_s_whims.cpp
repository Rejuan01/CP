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
    ll n, q;
    cin >> n >> q;
    vi d(q);
    for(ll i = 0; i < q; i++) cin >> d[i];
    for(ll i = 1; i < n; i++){
        cout << i << " " << i+1 << endl;
    }
    ll m = 2; // 1 will always be connected with m;
    for(auto i: d){
        ll x = n-i+1;
        if(m == x){
            cout << "-1 -1 -1" << endl; continue;
        }
        cout << "1 " << m << " " << x << endl;
        m = x;
    }
    
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