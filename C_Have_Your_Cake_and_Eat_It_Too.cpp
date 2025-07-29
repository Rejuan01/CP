#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll k;
const ll N = 2e5+2;
ll a[3][N];
bool calc(ll n, ll x, ll y, ll z){
    vi ans(6);
    ll s = 0, p = 0;
    ans[2*x] = p+1;
    while(s < k){
        s += a[x][p];
        p++;
    } ans[2*x+1] = p;
    s = 0;
    ans[2*y] = p+1;
    while(s < k && p < n){
        s += a[y][p];
        p++;
    } ans[2*y+1] = p;
    if(s < k){
        return false;
    }
    s = 0;
    ans[2*z] = p+1;
    while(p < n){
        s += a[z][p];
        p++;
    } ans[2*z+1] = p;
    if(s < k){
        return false;
    }
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
    return true;
}
void solve(){
    ll n;
    cin >> n;
    k = 0;
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < n; j++){
            cin >> a[i][j];
            k += a[i][j];
        }
    }
    k /= 3;
    k = (k+2)/3;
    if(calc(n, 0, 1, 2)) return;
    if(calc(n, 0, 2, 1)) return;
    if(calc(n, 1, 0, 2)) return;
    if(calc(n, 1, 2, 0)) return;
    if(calc(n, 2, 0, 1)) return;
    if(calc(n, 2, 1, 0)) return;
    cout << -1 << endl;

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