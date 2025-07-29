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
    map<ll, ll> m;
    m[0] = 3; m[1] = 1; m[2] = 2; m[3] = 1; m[5] = 1;
    
    for(ll i = 0; i < n; i++){
        auto it = m.find(a[i]);
        if(it != m.end()){
            it->second--;
            if(it->second == 0){
                m.erase(it);
            }
        }
        if(m.size() == 0){
            cout << i+1 << endl;
            return;
        }
    }
    cout << 0 << endl;
    
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