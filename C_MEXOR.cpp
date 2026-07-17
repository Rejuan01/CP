#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
using i128 = __int128;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
// const double PI = acos(-1.0);
// const long double PI_LD = acos(-1.0L);
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

bool check(ll x, ll y){
    while(x){
        x >>= 1;
        y >>= 1;
    }
    return y == 0;
}

void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    if(!check(n, k)){
        no; return;
    }
    if(n == 1){
        if(k != 1) no;
        else{
            yes;
            cout << 0 << endl;
        }
        return;
    }
    ll x = n^k;
    vi p;
    if(x < n){
        if(x) p.pb(x);
        p.pb(0);
        for(ll i = 1; i < n; i++){
            if(i != x) p.pb(i);
        }
    }
    else{
        ll y = -1;
        for(ll i = 1; i < n; i++){
            if((i^x) < n){
                y = (x^i);
                x = i;
                break;
            }
        }
        if(y == -1){
            no;
            return;
        }
        p.pb(y);
        p.pb(x);
        p.pb(0);
        for(ll i = 1; i < n; i++){
            if(i != x && i != y) p.pb(i);
        }
    }
    yes;
    rev(p);
    for(auto it: p) cout << it << " ";
    cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}