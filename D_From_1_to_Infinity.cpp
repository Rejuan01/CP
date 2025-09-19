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
ll fun(ll &x){
    ll m = x%10;
    ll res = m*(m+1)/2;
    x /= 10;
    res += x*45;
    ll s = 0, tmp = x;
    while(tmp){
        s += tmp%10; tmp /= 10;
    }
    if(x) x--;
    s *= (m+1);
    res += s;
    return res;
    
}
void solve(){
    ll k;
    cin >> k;
    ll a = 0, ans = 0;
    ll x = 1;
    while(a + 9*pow(10, x-1)*x <= k){
        a += 9*pow(10, x-1)*x;
        x++;
    }
    ll p = pow(10, x-1)-1;
    p += (k-a)/x;
    ll z = p+1;
    for(ll i = 0; i < x-(k-a)%x; i++) z/=10;
    while(z){
        ans += z%10;
        z/=10;
    }
    for(ll i = 0; p ; i++){
        ans += fun(p)*pow(10, i);
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