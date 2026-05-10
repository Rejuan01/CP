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
const ll N = 1e6+5;
bool p[N];
int c[N];
void check(ll x){
    ll k = x;
    while(k){
        if(k%10 == 0) return;
        k /= 10;
    }
    k = 10;
    while(k < x){
        if(!p[x%k]) return;
        k *= 10;
    }
    // all suffixes are prime and no 0 in x
    c[x] = 1;
}
void init(){
    memset(p, 1, sizeof(p));
    p[0] = p[1] = 0;
    for(ll i = 2; i < N; i++){
        if(p[i]){
            check(i);
            for(ll j = i*i; j < N; j += i){
                p[j] = 0;
            }
        }
    }
    for(ll i = 2; i < N; i++) c[i] += c[i-1];
}
// from spoj
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << c[n] << endl;
    }
    return 0;
}