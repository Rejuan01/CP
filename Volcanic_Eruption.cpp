#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
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
    ll n, p;
    cin >> n >> p;
    vi a(n), ans(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    bool flag = 0;  
    ll c = 0, mx = 0;
    for(ll i = 0; i < n; i++){ // left to right
        if(a[i] == 0){
            flag = 1; c = 1; continue;
        }
        if(!flag){                    // if no volcano faced till now
            ans[i] = 1e18; continue;
        }

        ll x = (a[i]+p-1)/p;
        if(c == 1) mx = x;   // c==1 means, the volcano is next to it
        else mx = max(mx, x);
        ans[i] = mx;
        c = 0;
    }
    flag = 0, c = 0, mx = 0;

    for(ll i = n-1; i >= 0; i--){ // right to left
        if(a[i] == 0){
            flag = 1; c = 1; continue;
        }
        if(!flag) continue;

        ll x = (a[i]+p-1)/p;
        if(c == 1) mx = x;
        else mx = max(mx, x);
        ans[i] = min(ans[i], mx);
        c = 0;
    }
    for(auto it: ans) cout << it << " ";
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