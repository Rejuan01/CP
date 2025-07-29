#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N = 1e6+10;
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
void solve(){
    ll n, x;
    cin >> n >> x;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(!isPrime[a[i]] || a[i] == 1) continue;
        ll l = 0, r = 0;
        for(ll j = i-x; j >= 0 && a[j] == 1; j-=x) l++;
        for(ll j = i+x; j < n && a[j] == 1; j+=x) r++;
        ans += l*r + l + r; 
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    sieve();
    while(t--){
       solve();
    }
    return 0;
}