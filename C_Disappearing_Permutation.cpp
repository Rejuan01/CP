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
    vi p(n+1);
    vector<bool> mark(n+1);
    for(ll i = 1; i <= n; i++) cin >> p[i];  
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll index; // d[i]
        cin >> index;
        while(!mark[index]){ // Can also mark by value, mark[p[index]]
            ans++;
            mark[index] = 1;
            index = p[index];
        }
        cout << ans << " ";
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