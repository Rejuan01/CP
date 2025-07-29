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
    vi a(n), b(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    vi ansMin, ansMax;
    ll l = n, r = n;
    ll slots = 0;
    for(ll i = n-1; i >= 0; i--){
        ll index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(slots == 0){
            r = l-1;
        }
        if(index < l){
           slots += l-index;
           l = index;
        }
        slots--;
        //cout << l << " " << r << endl;
        ansMin.push_back(b[l]-a[i]);
        ansMax.push_back(b[r]-a[i]);
    }
    for(ll i = n-1; i >= 0; i--){
        cout << ansMin[i] << " ";
    } cout << endl;
    for(ll i = n-1; i >= 0; i--){
        cout << ansMax[i] << " ";
    } cout << endl;
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