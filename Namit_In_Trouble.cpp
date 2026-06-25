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
const ll N = 1e5;
bool isPrime[N+1];
vi primes;
void init(){
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for(ll i = 2; i*i <= N; i++){
        if(isPrime[i])
        for(ll j = i*i; j <= N; j += i){
            isPrime[j] = 0;
        }
    }
    for(ll i = 2; i <= N; i++){
        if(isPrime[i]) primes.pb(i);
    }
}
void solve(ll tc){
    ll n, k;
    cin >> n >> k;
    ll x = sqrtl(k), y = sqrtl(n);
    ll i = upper_bound(primes.begin(), primes.end(), x)-primes.begin();
    ll j = upper_bound(primes.begin(), primes.end(), y)-primes.begin();
    cout << j << " " << max(0LL, j-i) << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    init();
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}