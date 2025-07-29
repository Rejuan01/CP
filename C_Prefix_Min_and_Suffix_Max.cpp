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
    vi a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ll x = *min_element(a.begin(), a.end());
    ll y = *max_element(a.begin(), a.end());
    vi mx(n+1), mn(n+1);
    mn[0] = 1e9;
    for(ll i = 1; i <= n; i++){
        mn[i] = min(mn[i-1], a[i]);
    }
    mx[n] = a[n];
    for(ll i = n-1; i > 0; i--){
        mx[i] = max(mx[i+1], a[i]);
    }
    string s = "";
    for(ll i = 1; i <= n; i++){
        if(i == 1 || i == n){
            s.push_back('1');
            continue;
        }
        if(a[i] == x || a[i] == y){
            s.push_back('1');
            continue;
        }
        if(mn[i] == a[i] || mx[i] == a[i]){
            s.push_back('1');
        }else{
            s.push_back('0');
        }
    }
    cout << s << endl;
    
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