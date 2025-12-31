#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define abd cout<<"abundant"<<endl
#define dfc cout<<"deficient"<<endl
#define pft cout << "perfect" << endl
const ll N = 1e6+5;
vi divSum(N, 0);
void init(){
    for(ll i = 1; i < N; i++){
        for(ll j = i; j < N; j += i){
            divSum[j] += i;
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    ll s = divSum[n]-n;
    if(s == n) pft;
    else if (s < n) dfc;
    else abd;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while(t--){
       solve();
    }
    return 0;
}