#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
void solve(ll tc){
    ll n;
    cin >> n;
    vi a, b, c, d;
    for(ll i = 0; i < n; i++){
        ll x; cin >> x;
        if(x%6 == 0) a.pb(x);
        else if(x%3 == 0) b.pb(x);
        else if(x%2 == 0) c.pb(x);
        else d.pb(x);
    }
    if(d.size()){
        for(auto it: a) cout << it << " ";
        for(auto it: b) cout << it << " ";
        for(auto it: d) cout << it << " ";
        for(auto it: c) cout << it << " ";
        cout << endl;
    }
    else{
        for(auto it: b) cout << it << " ";
        for(auto it: a) cout << it << " ";
        for(auto it: c) cout << it << " ";
        cout << endl;
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}