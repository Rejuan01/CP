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
    ll n, m;
    cin >> n >> m;
    vi a(m), v;       // uninfected in gaps
    for(ll i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(ll i = 0; i < m-1; i++){
        v.push_back(a[i+1] - a[i] - 1);
    }
    v.push_back(n - (a[m-1]-a[0]+1));
    sort(v.begin(), v.end(), greater<ll>());
    ll prot = 0; // total protected
    ll inf = 0; // newly infected in gaps
    for(ll i = 0; i < m; i++){
        ll p = v[i]-inf; // procted in current gaps
        if(p <= 0){
            cout << n-prot << endl;
            return;
        }
        if(p == 1){
            prot++;
        }else{
            prot += p-1;
        }
        inf += 4;
    }
    cout << n-prot << endl;
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