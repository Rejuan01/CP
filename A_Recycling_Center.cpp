#include<bits/stdc++.h>
using namespace std;
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
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n) , c;
    for(ll i = 0; i < n; i++){ 
        cin >> a[i];
        ll x = a[i];
        ll c1 = 0;
        while(x <= k){
            x*=2;
            c1++;
        }
        if(c1) c.push_back(c1);
    }
    sort(c.begin(), c.end());
    ll x = 1;
    ll s = 0;
    for(auto it: c){
        if(it >= x){
            s++;
            x++;
        }
    }
    cout << n-s << endl;
    
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