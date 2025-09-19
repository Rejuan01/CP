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
    vi a(n+1);
    vector<bool> c(n+1);
    ll k = 0;
    ll idx = -1;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        c[a[i]] = 1;
        if(a[i] == 0){
            k++;
            idx = i;
        }
    }
    if(k == 1){
        for(ll i = 1; i <= n; i++){
            if(!c[i]){
                a[idx] = i; break;
            }
        }
    }
    ll l = 1, r = n;
    while(l <= n && a[l] == l) l++;
    while(r > l && a[r] == r) r--;
    // cout << l << " " << r << endl;
    cout << r-l+1 << endl;
    
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