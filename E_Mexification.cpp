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
ll cal(vi &a){
    ll n = a.size();
    vi c(n+1);
    for(auto it: a) c[it]++;
    ll m = n, s = 0;
    for(ll i = 0; i < n+1; i++){
        if(c[i] == 0){
            m = i; break;
        }
    }
    for(ll i = 0; i < n; i++){
        if(m < a[i] || c[a[i]] > 1) a[i] = m; 
        s += a[i];      
    } 
    return s; 
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n), c(n+1), b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = cal(a);
    if(k == 1){
        cout << ans << endl; return;
    }
    ans = cal(a);
    if(k%2 == 0){
        cout << ans << endl; return;
    }
    ans = cal(a);
    cout << ans << endl;
}
// repeats after 2nd and 3rd calculations
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