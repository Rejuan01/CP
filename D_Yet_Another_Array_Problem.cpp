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
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll N = 3000+1;
bool isPrime[N];
vi primes;
ll k = 1;
void init(){
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i < N; i++){
        if(isPrime[i]){
            primes.pb(i);
            k *= i;
            for(ll j = i*i; j < N; j += i){
                isPrime[j] = false;
            }  
        }
    }
    // cout << primes.size() << " " << primes.back() << " " << k << endl;
    // multiplication of primes till 53 is > 1e18
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    ll x = 1e18+5;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(auto p: primes){
        for(ll i = 0; i < n; i++){
            if(a[i]%p){
               cout << p << endl;
                return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}