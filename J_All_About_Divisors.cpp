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

const ll N = 1e6, MOD = 1e7+7;

bool isPrime[N+1];
vi primes;

void init(){
    for(ll i = 2; i <= N; i++) isPrime[i] = 1;
    for(ll i = 2; i <= N; i++){
        if(isPrime[i]){
            primes.pb(i);
            for(ll j = i; j <= N; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

void solve(ll n){

    ll ans = 1;
    for(auto p: primes){   // legendre's formula
        ll x = n, e = 0;
        while(x){
            x /= p;
            e += x;
        }
        ll k = (e+1)*(e+2)/2 % MOD;
        ans = (ans*k)%MOD;
    }

    cout << ans << endl;

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    init();

    while(1){
        ll n;
        cin >> n;
        if(!n) break;
        solve(n);
    }
    return 0;
}