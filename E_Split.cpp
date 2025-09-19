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
    vi a(n), c(n+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]]++;
    }
    for(ll i = 0; i < n; i++){
        if(c[a[i]]%k != 0){
            cout << 0 << endl;
            return;
        }
    } 
    ll l = 0, r = 0;
    ll ans = 0;
    vi mp(n+1);
    while(r < n){
        ll x = a[r];
        mp[x]++;
        if(mp[x] <= c[x]/k) ans += r-l+1;
        else{
            while(mp[x] > c[x]/k){ 
                mp[a[l]]--;
                l++;
            }
            ans += r-l+1;
        }
        r++;
    }
    cout << ans << endl;
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