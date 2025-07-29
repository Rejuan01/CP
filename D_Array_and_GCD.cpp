#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N =  6e6+20;
bool isPrime[N];
vi p;
void sieve(){
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i * i < N; i++){
        if(!isPrime[i]) continue;
        for(ll j = i * i; j < N; j += i){
            isPrime[j] = false;
        }
    }
    p.push_back(0);
    for(ll i = 2; i < N; i++){
        if(isPrime[i]) p.push_back(i);
    }
    for(ll i = 1; i < p.size(); i++){
        p[i] += p[i-1];  // sum of first i primes
    }
}
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    sort(a.begin(), a.end());

    for(ll i = 1; i <= n; i++) a[i] += a[i-1];

    ll s = a.back();
    // ll m = 4e5+10;
    // cout << p.size() << endl;
    // cout << p[m] << endl;
    for(ll i = 0; i < n; i++){
        ll x = s-a[i];
        if(p[n-i] <= x || i > n-2){   
            cout << i << endl;
            return;
        }
    }
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