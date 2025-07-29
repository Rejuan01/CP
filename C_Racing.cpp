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
    vi d(n), l(n), r(n);
    for(ll i = 0; i < n; i++) cin >> d[i];
    for(ll i = 0; i < n; i++) cin >> l[i] >> r[i];
    ll p = 0, q = 0;
    for(ll i = 0; i < n; i++){
        if(d[i] == 1){
            p++; q++;
        }else if(d[i] == -1) q++;
        p = max(p, l[i]);
        q = min(q, r[i]);
        if(p > q){
            cout << -1 << endl;
            return;
        }
    }
    //cout << p << " " << q << endl;
    for(ll i = n-1; i >= 0; i--){
        if(d[i] == 1){
            p--;
        }else if(d[i] == -1){
            if(p <= r[i] && p >= l[i]){
                d[i] = 0;
            }else{
                d[i] = 1;
                p--;
            }
        }
        cout << d[i] << " " << p << endl;
    }
    for(auto it: d){
        cout << it << " ";
    } cout << endl;
    
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