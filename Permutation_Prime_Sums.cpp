#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
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
const ll N = 1e5+10;
bool isPrime[N];
void sieve(){
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i * i < N; i++){
        if(!isPrime[i]) continue;
        for(ll j = i * i; j < N; j += i){
            isPrime[j] = false;
        }
    }
}
vi b;
bool calc(ll n){
    if(n == 1){
        b[1] = 1;
        return 1;
    }
    if(n < 1) return 1;
    ll x = 1;
    while(x < n){
        if(!isPrime[n+x]) x++;
        else break;
    }
    if(x == n) return 0;
    for(ll i = x; i <= n; i++){
        b[i] = n+x-i;
    }
    return calc(x-1);
}
void solve(){
    ll n;
    cin >> n;
    b.resize(n+1);
    bool flag = calc(n); 
    if(!flag){               // This would not occur anytime ;) 
        cout << "IMPOSSIBLE" << endl; return;
    }
    for(ll i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
    for(ll i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    solve();
    return 0;
}