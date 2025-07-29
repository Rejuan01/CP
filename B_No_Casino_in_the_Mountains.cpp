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
    ll l = 0;
    ll ans = 0;
    while(l < n){
        ll c = 0;
        while(l < n){
            if(a[l] == 0){
                c++;
                l++;
                if(c == k){
                    l++;
                    ans++;
                    break;
                }
            }else{
                c = 0;
                l++;
                break;
            }
        }
    }
    cout << ans << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}