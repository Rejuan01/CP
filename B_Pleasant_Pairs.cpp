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
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll count = 0;
    for(ll i = 0; i < n; i++){
        ll k = (2*(i+1))/a[i]+1;  // in one bases index, i < j so, i < k*a[i]-i; k > 2i/a[i]
        ll j = k*a[i]-(i+1)-1; // smallest j after i
        for(; j < n; j+=a[i]){
            if(a[i]*a[j] == i+j+2){
                count++; 
            }
        }
    }
    cout << count << endl;
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