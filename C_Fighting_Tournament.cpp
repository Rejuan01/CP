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
    ll n, q;
    cin >> n >> q;
    vi a(n+1), idx(n+1); // max value and max index till i
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > a[i-1]){
            idx[i] = i;
        }else{
            idx[i] = idx[i-1];
        }
        a[i] = max(a[i], a[i-1]);
    }
    while(q--){
        ll i, k;
        cin >> i >> k;
        if(k < i-1 || (idx[i] != i) || (i == 1 && (idx[2] != 1))){
            cout << 0 << endl; continue;
        }
        if(idx[n] == i){
            if(i < 3){
                cout << k << endl; continue;
            }
            cout << k-i+2 << endl; continue;
        }
        ll in = lower_bound(idx.begin(), idx.end(), i+1) - idx.begin(); // first index where i loses
        if(i < 3){
            cout << min(in-2, k) << endl;
        }
        else{
            cout << min(in-i, k-i+2) << endl;
        }
        
    }

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