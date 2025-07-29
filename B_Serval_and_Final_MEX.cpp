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
    vi a(n);
    bool flag = false;
    ll x = 0, y = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0){
            if(i < n/2) x++;
            else y++;
        }
    }
    if(x == 0 && y == 0){
        cout << 1 << endl;
        cout << 1 << " " << n << endl; return;
    }
    ll k = 0;
    if(y){
        if(x){
            cout << 3 << endl;
            cout << n/2 + 1 << " " << n << endl;
            cout << 1 << " " << n/2 << endl;
            cout << 1 << " " << 2 << endl;
        }else{
            cout << 2 << endl;
            cout << n/2 + 1 << " " << n << endl;
            cout << 1 << " " << n/2 + 1 << endl;
        }
    }else{
        cout << 2 << endl;
        cout << 1 << " " << n/2 << endl;
        cout << 1 << " " << n-n/2 + 1 << endl;
    }
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