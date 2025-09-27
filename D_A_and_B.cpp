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
    string s;
    cin >> n >> s;
    vi pa(n+1), pb(n+1), sa(n+2), sb(n+2); // dp
    ll a = 0, b = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'a'){
            pa[i+1] = pa[i];
            pb[i+1] = pb[i]+b;
            a++;
        }
        else{
            pa[i+1] = pa[i]+a;
            pb[i+1] = pb[i];
            b++;
        }
    }
    a = 0, b = 0;
    for(ll i = n-1; i >= 0; i--){
        if(s[i] == 'a'){
            sa[i+1] = sa[i+2];
            sb[i+1] = sb[i+2]+b;
            a++;
        }
        else{
            sa[i+1] = sa[i+2]+a;
            sb[i+1] = sb[i+2];
            b++;
        }
    }
    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i <= n; i++){
        ll k = min(pa[i]+sa[i], pb[i]+sb[i]);
        ans = min(ans, k);
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