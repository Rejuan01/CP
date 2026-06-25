#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
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
const ll N = 102000000;
bitset<N+1> bs;
vi p, a, b;
void init(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 3; i*i <= N; i += 2){
        if(bs[i])
        for(ll j = i*i; j <= N; j += 2*i){
            bs[j] = 0;
        }
    }
    p.pb(2);
    for(ll i = 3; i <= N; i += 2) if(bs[i]) p.pb(i);
    ll cnt = 0;
    a.assign(p.size()+1, 0);    
    b.assign(p.size()+1, 0);
    for(ll i = 0; i < p.size(); i++){
        ll x = p[i];
        ll c1 = 0, c2 = 0;
        while(x){
            c1++;
            if(x&1) c2++;
            x >>= 1;
        }
        a[i+1] = c1;
        b[i+1] = c2;
        if(i > 0){
            a[i+1] += a[i];       // total no of bits till [p[0], p[i]]
            b[i+1] += b[i];       // total no of set bits
        }
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    ll i = lower_bound(a.begin(), a.end(), n) - a.begin();
    if(a[i] == n){
        cout << b[i] << endl; return;
    }
    ll x = a[i], k = p[i-1], y = b[i];
    while(x >= n){
        if(k&1 && x == n) break;
        x--;
        if(k&1) y--;
        k >>= 1;
    }
    cout << y << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    init();
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}