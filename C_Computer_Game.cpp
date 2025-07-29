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
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    if(k <= b*n){
        cout << -1 << endl;
        return;
    }
    if(k > a*n){
        cout << n << endl;
        return;
    }
    ll x = (k - b*n)/(a-b);
    if((k - b*n)%(a-b) == 0) x--;
    cout << x << endl;
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