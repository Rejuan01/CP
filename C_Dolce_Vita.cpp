#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, x;
    cin >> n >> x;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll c = 0; // last day cost
    ll count = 0;
    for(ll i = 0; i < n; i++){
        if(c + a[i] <= x){
            c += a[i];
            count++;
        }else break;
    }
    ll ans = count;
    ll k = count-1; // index of last shop
    ll day = 1;
    while(k >= 0){
        ll p = (x-c)/(k+1); // next how many days I can go to the same number of shops
        if(p > 0){
            ans += p*(k+1); // number of packs I can buy
            c += p*(k+1);   // latest cost increased 
            day += p; continue;
        }
        c += k+1;
        while(k >= 0 && c > x){
            c -= a[k]+day;
            k--;
        }
        if(k >= 0){
            ans += k+1;
            day++;
        }
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}