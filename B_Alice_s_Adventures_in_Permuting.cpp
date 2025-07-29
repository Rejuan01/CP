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
    ll n, b, c; 
    cin >> n >> b >> c;
    if(c > n-1){
        cout << n << endl;
        return;
    }
    if(b == 0){ // all values are c 
        if(c < n-2){
            cout << -1 << endl;
        }else{
            cout << n-1 << endl;
        }
        return;
    }
    cout << n - max(0LL, (n-1-c)/b + 1) << endl; // i*b+c > n-1
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