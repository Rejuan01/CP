#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define ull unsigned long long
#define ut uint64_t
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

const ll N = 1e6, mod = 1e9+7, mod1 = 1e9+9;
ll spf[N+1];

mt19937_64 rng(
    chrono::steady_clock::now().time_since_epoch().count()
);

unordered_map<ll, uint64_t> rnd;

void init() {
    for (ll i = 1; i <= N; i++) spf[i] = i;

    for (ll j = 4; j <= N; j += 2)
        spf[j] = 2;

    for (ll i = 3; i * i <= N; i += 2) {
        if (spf[i] == i) {
            for (ll j = i * i; j <= N; j += 2 * i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i){
            rnd[i] = rnd[i] = uniform_int_distribution<ll>(1, (ll)1e18)(rng);
        }
    }
}

void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n);

    vector<ut> b(n);       // b[i] = hash of odd frequency of pf of a[i]
    map<ut, ll> mp;        // how many times a hash occurred in b

    for(ll i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, q = 0;

    for(ll i = 0; i < n; i++){
        vi p;
        ll it = a[i], q1 = 0;
        while(it != 1){
            ll x = spf[it];
            bool f = 0;
            while(it != 1 && it%x == 0){
                it /= x;
                f ^= 1;
            }
            if(f){
                p.pb(x);
                q ^= rnd[x];
                q1 ^= rnd[x];
            }
        }
        mp[q1]++;
        b[i] = q;
    }

    for(auto it: b){
        ans += mp[it];
    }
    cout << ans << endl;
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