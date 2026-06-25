#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll int
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
const ll N = 2e7;
ll spf[N+1];
ll pd[N+1];

ll div_count(ll x){        // how many ways x can be expressed as a*b such that gcd(a,b) = 1
    ll cnt = 0;
    while(x != 1){
        ll k = spf[x];
        while(x != 1 && x%k == 0){
            x /= k;
        }
        cnt++;
    }
    return 1<<cnt;
}

void init(){
    for(ll i = 1; i <= N; i++) spf[i] = i;
    for(ll i = 2; i <= N; i++){
        if(spf[i] == i)
        for(long long j = (long long) i*i; j <= N; j += i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
        pd[i] = div_count(i);
    }
    pd[1] = 1;
}

void solve(ll tc){
    ll c, d, x;

    cin >> c >> d >> x;

    ll ans = 0;
    for(ll g = 1; g*g <= x; g++){
        if(x%g == 0){

            ll k = (x/g + d);
            if(k%c == 0){
                k /= c;
                ans += pd[k];
            }
            if(g != x/g){              // for gcd = x/g
                k = g+d;
                if(k%c == 0){
                    k /= c;
                    ans += pd[k];
                }
            }
        }
    }
    cout << ans << endl;
}
/*
     cab /g - dg = x
    (c.a1.b1 - d).g = x    [a1 = a/g & b1 = b/g]

    So, g is among the divisors of x.
    for each g, I need to find no of ways I can get (a1, b1) such that gcd(a1, b1) = 1

    ******** using int for optimization ******** ;(
    
*/
int32_t main(){
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