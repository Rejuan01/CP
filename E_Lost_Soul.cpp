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
    if(a[n-1] == b[n-1]){
        cout << n << endl; return;
    }
    set<ll> sa, sb;
    ll i = n-2, idx = -1;
    while(i >= 0){
        if((a[i] == b[i]) || (b[i+1] == b[i]) || (a[i+1] == a[i]) || (sa.find(a[i]) != sa.end()) || (sb.find(b[i]) != sb.end()) || (sa.find(b[i]) != sa.end()) || (sb.find(a[i]) != sb.end())){
            idx = i;
            break;
        }
        sa.insert(a[i+1]);
        sb.insert(b[i+1]);
        i--;
    }
    cout << idx+1 << endl;
    // sa = set<ll>(), sb = set<ll>();
    // i = n-2;
    // while(i > idx){
    //     if((sa.find(b[i]) != sa.end()) || (sb.find(a[i]) != sb.end())){
    //         idx = max(idx, i);
    //         break;
    //     }
    //     sa.insert(a[i+1]);
    //     sb.insert(b[i+1]);
    // }
    // cout << idx+1 << endl;
    
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