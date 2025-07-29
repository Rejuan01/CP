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
    ll a = 0, b = 0;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            a = i;
            n /= i;
            break;
        }
    }
    if(a == 0){
        no; return;
    }
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0 && i != a && (n/i) != a && i != (n/i)){
            yes;
            cout << a << " " << i << " " << n/i << endl;
            return;
        }
    }
    no;
    
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