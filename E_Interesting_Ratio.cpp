#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
const ll N = 1e7 + 10;
bool isPrime[N];
vi p;
void sieve(){
    fill(isPrime, isPrime + N, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i < N; i++){
        if(isPrime[i]){
            p.push_back(i);
            if (i*i < N) {
                for(ll j = i * i; j < N; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i < n; i++){
        ll x = n/i;
        ll idx = upper_bound(p.begin(), p.end(), x) - p.begin();
        ans += idx;
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