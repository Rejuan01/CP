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
    vi a(2*n+1), b(2*n+1);
    for(ll i = 0; i < 2*n; i++){
        ll x; cin >> x;
        a[x]++;
    }
    ll c = 0;
    ll x = 0, y = 0;
    ll ans = 0;
    for(ll i = 1; i <= 2*n; i++){
        if(a[i] == 0) continue;
        if(a[i]%2 == 0){
            a[i]--;
            b[i]++; 
            c++;
            y += a[i]; 
            ans += 2; 
        }
        else{
            x += a[i];
            ans++;
        }
        if(c == n) break;
    }
    if(n-c < x){
        cout << ans << endl;
        return;
    }
    else if(((n-c)&1)&& x == 0) ans -= 2;
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