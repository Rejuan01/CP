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
    ll n, k;
    cin >> n >> k;
    vi a(n+1);
    for(ll i = 1; i <= n; i++) a[i] = i;
    if(k&1){
        no; return;
    }
    ll l = 1, r = n;
    while(l < r){
        ll x = (r-l)*2;
        if(x <= k){
            k -= x;
            swap(a[l], a[r]);
        }
        else if(x-k == 2 && r-l > 1){
            swap(a[l+1], a[r]);
            k = 0;
        }
        if(k == 0) break;
        l++, r--;
    }
    if(k){
        no; return;
    }
    yes;
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
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