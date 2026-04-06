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
bool isPrime[3000000];
vi p;
void init(){
    fill(isPrime, isPrime+3000000, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i*i < 3000000; i++){
        if(isPrime[i]){
            for(ll j = i*i; j < 3000000; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(ll i = 2; i < 3000000 && p.size() < 10005; i++){
        if(isPrime[i]) p.pb(i);
    }
}
void solve(ll tc){
    ll n;
    cin >> n;
    vi a(n+2);
    for(ll i = 1; i <= n+1; i++) a[i] = p[i-1];
    for(ll i = 1; i <= n; i++){
        cout << a[i]*a[i+1] << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    init();
    int t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}