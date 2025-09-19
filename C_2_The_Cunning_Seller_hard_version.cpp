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

ll findMin(ll n){
    ll ans = 0;
    while(n){
        ll x = 0;
        while(pow(3, x) <= n) x++;
        if(pow(3, x) > n) x--;
        n -= pow(3, x);
        ans += pow(3, x+1) + x*pow(3, x-1);
    }
    return ans;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll step = 0;
    ll m = n;
    if(n <= k){
        cout << 3*n << endl; return;
    }
    vi a, b;
    for(ll i = 0; pow(3, i) <= n; i++){
        a.pb(pow(3, i));
        if (i == 0) b.pb(pow(3, i+1));
        else b.pb(pow(3, i+1) + i*pow(3, i-1));
    }
    for(ll i = 0; i < a.size(); i++){
        // ll l = 
    }
    
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