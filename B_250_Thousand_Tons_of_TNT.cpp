#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll m = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    vi f;       // all factors of n
    for(ll i = 2; i*i <= n; i++){ 
        if(n%i == 0){
            f.push_back(i);
            if(i != n/i){
                f.push_back(n/i);
            }
        }
    }
    for(ll i = 0; i < f.size(); i++){
        vi p;
        ll s = 0;
        ll c = 0;
        for(ll j = 0; j < n; j++){
            s += a[j]; c++;
            if(c == f[i]){
                p.push_back(s);
                s = 0; c = 0;
            }
        }
        ll x = *max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end());
        m = max(m, x);
    }
    cout << m << endl;

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