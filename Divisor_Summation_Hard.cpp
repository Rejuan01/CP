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
const ll N = 1e8;
vi primes;
bitset<N/2+1> b;
void init(){
    b.set();
    for(ll i = 3; i*i <= N; i += 2){
        if(b[i/2])
        for(ll j = i*i; j <= N; j += 2*i){
            b[j/2] = 0;
        }
    }
    primes.pb(2);
    for(ll i = 3; i <= N; i += 2){
        if(b[i/2]) primes.pb(i);
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    ll ans = 1, k = n;
    for(auto p: primes){
        if(p*p > k) break;
        ll x = p;
        while(k%p == 0){
            k /= p;
            x *= p;
        }
        ans *= (x-1)/(p-1);
    }
    if(k > 1) ans *= (k+1);  // (k*k-1)/(k-1) = k+1
    cout << ans-n << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    init();
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}