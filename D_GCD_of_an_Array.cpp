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
const ll mod = 1e9+7;
const ll N = 2e5;
ll spf[N+1];
void init(){
    for(ll i = 1; i <= N; i++) spf[i] = i;
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i)
        for(ll j = i*i; j <= N; j += i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}
void solve(){
    ll n, q;
    cin >> n >> q;

    ll g = 0;
    vi a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        g = __gcd(g, a[i]);
    }

    map<ll, multiset<ll>> mp;
    vector<map<ll, ll>> v(n+1);

    for(ll i = 0; i < n; i++){
        ll it = a[i];
        while(it != 1){
            ll k = spf[it], c = 0;
            while(it != 1 && it%k == 0){
                c++;
                it /= k;
            }
            mp[k].insert(c);
            v[i][k] = c;
        }
    }

    while(q--){
        ll i, x;
        cin >> i >> x;
        i--;

        ll it = x;
        while(it != 1){                         // add new factors
            ll k = spf[it], c = 0;
            while(it != 1 && it%k == 0){
                c++;
                it /= k;
            }

            ll prev = 0;
            if(mp[k].size() == n) prev = *mp[k].begin();  // if facor k isn't in all elements the power is considered zero

            if(mp[k].find(v[i][k]) != mp[k].end()){    // if same factor was already before
                mp[k].erase(mp[k].find(v[i][k]));
            }   

            c += v[i][k];
            mp[k].insert(c);
            v[i][k] = c;

            ll now = 0;
            if(mp[k].size() == n) now = *mp[k].begin();

            for(ll i = prev; i < now; i++) g = (g*k)%mod;
        }
        cout << g << endl;
    }
    
}
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