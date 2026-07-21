#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;

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

const ll N = 5e6, MOD = 1e8+7;
ll spf[N+1];
ll mx = 0, id = 0;
vi v, primes, idx(N+1, -1);
map<ll, ll> ans;

void sieve(){
    for (ll i = 2; i <= N; i++) {
        if (!spf[i]) {
            spf[i] = i;
            primes.push_back(i);
            idx[i] = primes.size()-1;
        }
        for (ll p : primes) {
            if (1LL * p * i > N) break;
            spf[p * i] = p;
            if (p == spf[i]) break;
        }
    }
}

void init(){

    ll m = primes.size();
    vi total(m), pf_i(m), last_update(m);     // pf of: total (1!*2!*...i!), factorial of current value (i!), last for which i, a prime's exponent is updated (only updated when answer is needed or exponent is changed else TLE ;( )

    for(ll i = 1; i <= N && id < v.size(); i++){
        ll x = i;
        
        while(x != 1){
            ll p = spf[x], e = 0;
            while(x != 1 && x%p == 0){
                x /= p;
                e++;
            }
            ll k = idx[p];                               // p is the k th prime
            total[k] += (i-last_update[k]-1)*pf_i[k];
            pf_i[k] += e;
            total[k] += pf_i[k];
            last_update[k] = i;
        }

        if(v[id] == i)
        {
            for(ll k = 0; k < m; k++){
                total[k] += (i-last_update[k])*pf_i[k];
                last_update[k] = i;
            }
            
            id++;
            ll a = 1;
            
            for(auto e: total){
                ll exp = e%MOD;
                a = a*(exp+1) % MOD;
            }
            ans[i] = (ll)a;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vi in;
    while(1){
        ll n;
        cin >> n;
        if(n) in.pb(n);
        else break;
    }

    v = in;
    ssort(v);

    sieve();
    init();
    
    for(auto n: in) cout << ans[n] << '\n';
    
    return 0;
}