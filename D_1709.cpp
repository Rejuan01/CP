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
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; i++){
        if(b[i] < a[i]){
            swap(a[i], b[i]);
            v.push_back({3, i+1});
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                v.push_back({1, j+1});
            }
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n-i-1; j++){
            if(b[j] > b[j+1]){
                swap(b[j], b[j+1]);
                v.push_back({2, j+1});
            }
        }
    }
    cout << v.size() << endl;
    for(auto &[p, q]: v){
        cout << p << " " << q << endl;
    }
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