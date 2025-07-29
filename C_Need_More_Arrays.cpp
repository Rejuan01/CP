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
    vi a;
    for(ll i = 0; i < n; i++){
        ll p; cin >> p;
        if(a.size() == 0 || a.back() != p) a.push_back(p); 
    }
    ll m = a.size();
    ll ans = 0;
    //cout << "* " << m << endl;
    for(ll i = 0; i < m; i++){
        ans++;
        //cout << a[i] << " ";
        if(i < m-1 && a[i+1] == a[i]+1){
            i++; 
            continue;
        }
    }
    //cout << endl;
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