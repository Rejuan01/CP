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

const ll N = 2e5;
ll spf[N+1];

void init(){
    for(ll i = 1; i <= N; i++) spf[i] = i;
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i)
        for(ll j = i*i; j <= N; j += i){
            if(spf[j] == j) spf[j] = i;
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    map<ll, ll> mn, s_mn, cnt;
    for(auto it: a){
        // cout << it << endl;
        while(it != 1){
            ll x = spf[it], c = 0;
            while(it != 1 && it%x == 0){
                c++;
                it /= x;
            }
            // cout << x << " " << c << endl;
            if(mn.count(x) == 0) mn[x] = 1e9;
            
            if(c <= mn[x]){
                s_mn[x] = mn[x];
                mn[x] = c;
            }
            else if(c < s_mn[x]) s_mn[x] = c;
            cnt[x]++;
        }
    }
    ll ans = 1;
    for(auto [p, q]: cnt){
        // cout << p << " " << mn[p] << " " << s_mn[p] << endl;
        if(q == n){
            ll k = s_mn[p];
            while(k--) ans *= p;
        }
        else if(q == n-1){         
            ll k = mn[p];            // one element with p^0 in its factorization. So mn[p] = 0, s_mn[p] = mn[p]
            while(k--) ans *= p;
        }
        // else mn[p] = s_mn[p] = 0 as atleast 2 values have p^0 in their pf
    }
    cout << ans << endl;
}

// ans is the second min power of all prime factors

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    init();
    solve();
    return 0;
}