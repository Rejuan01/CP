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
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll N = 1e7+5;
ll spf[N];
void init(){
    for(ll i = 1; i < N; i++) spf[i] = i;
    for(ll i = 2; i*i < N; i++){
        if(spf[i] == i){
            for(ll j = i*i; j < N; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    ll n;
    while (cin >> n) {
        string res = "1";
        while (n > 1) {
            res += " x " + to_string(spf[n]);
            n /= spf[n];
        }
        cout << res << '\n';
    }
}