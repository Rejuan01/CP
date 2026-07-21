#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll int
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

const ll N = 1e4+1;          

ll sig[N*N], rem[N*N], inv[N*N];
bool b[N];
vi primes;

void init(){
    for(ll i = 2; i*i < N; i++){
        if(!b[i]){
            for(ll j = i*i; j < N; j += i){
                b[j] = 1;
            }
        }
    }

    for(ll i = 2; i < N; i++) if(!b[i]) primes.pb(i);

    for(ll i = 1; i < N*N; i++){
        rem[i] = i;
        sig[i] = 1;
    }
    for(auto p: primes){
        for(ll i = p; i < N*N; i += p){
            ll s = 1;
            do {
                rem[i] /= p;
                s = s*p + 1;
            } while(rem[i]%p == 0);

            sig[i] *= s;
        }
    }
    for(ll i = N; i < N*N; i++){
        if(rem[i] > 1){
            sig[i] *= (1+rem[i]);
        }
    }

    for(ll i = 1; i < N*N; i++){
        if(sig[i] < N*N && inv[sig[i]] == 0){
            inv[sig[i]] = i;
        }
    }

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
    while(t--){
        ll n;
        cin >> n;
        if(inv[n] == 0) cout << -1 << endl;
        else cout << inv[n] << endl;
    }
    return 0;
}