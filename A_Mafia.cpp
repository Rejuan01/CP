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
bool check(vi &a, ll m){
    ll s = 0;
    for(auto it: a){
        s += m-it;
        if(s >= m) return true;
    }
    return false;
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);
    ll l = 1, r = 1e15;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        l = max(l, a[i]);
    }
    l--;
    while(l+1 < r){
        ll m = (l+r)/2;
        if(check(a, m)) r = m;
        else l = m;
    }
    cout << r << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}