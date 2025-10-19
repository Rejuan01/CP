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

const ll N = 2e5+10; // limit
ll spf[N + 1];    // smallest prime factor

void sieve() {
    for (ll i = 0; i <= N; i++) spf[i] = i;

    for (ll i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i is prime
            for (ll j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vector<ll> get_factors(ll n, vi &factors) {
    factors.clear();
    while (n > 1) {
        ll p = spf[n];
        factors.push_back(p);
        while (n % p == 0) n /= p;  // skip duplicates
    }
    return factors;
}

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    ll b;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b;
    ll x = 0, y = 0;
    for(auto it: a){
        if(it%2 == 1 && it != 1) y++;
        if(it%2 == 0) x++;
    }
    if(x > 1){
        cout << 0 << endl; return;
    }
    vi factors;
    vector<bool> v(2e5+20);
    for(ll i = 0; i < n; i++){
        if(a[i] == 1) continue;
        get_factors(a[i], factors);
        for(auto it: factors){
            if(v[it]){ // 2 num has gcd > 1
                cout << 0 << endl;
                return;
            }
            v[it] = 1;
        }
    }
    for(ll i = 0; i < n; i++){
        if(a[i] == 1) continue;
        get_factors(a[i]+1, factors);
        for(auto it: factors){
            if(v[it]){ 
                cout << 1 << endl;
                return;
            }
        }
        // cout << endl;
    }
    if(x == 1){
        cout << 1 << endl;
    } 
    else cout << 2 << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    sieve();
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}