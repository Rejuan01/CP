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
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll p = a[n/2];
    ll c = 0;
    ll ans = 0;
    for(ll i = n/2; i < n;){
        ll j = i;
        while(j < n && a[j] == p){
            c++; j++;
        }
        if(j < n){
            ll y = a[j]-a[i];
            if(c*y <= k){
                ans += y;
                k -= c*y;
            }else{ // c*y > k
                ans += k/c;
                break;
            }
        }else{
            ans += k/c;
            break;
        }
        i = j;
        p = a[j];
    }
    cout << a[n/2]+ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}