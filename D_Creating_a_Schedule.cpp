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
    vi a(m);
    for(ll i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll p = 0, q = m-1;
    ll c = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < 3; j++){
            cout << a[p] << " " << a[q] << " ";
        } cout << endl;
        i++;
        if(i == n) break;
        for(ll j = 0; j < 3; j++){
            cout << a[q] << " " << a[p] << " ";
        }cout << endl;
        p++; q--;
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