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
    ll m, s;
    cin >> m >> s;
    if(s == 0){
        if(m == 1){
            cout << 0 << " " << 0 << endl;
        }else{
            cout << -1 << " " << -1 << endl;
        }return;
    }if(s > 9*m){
        cout << -1 << " " << -1 << endl;
        return;
    }
    vi a;
    ll x = s;
    for(ll i = m; i > 0; i--){
        if(x > 9){
            a.push_back(9);
            x -= 9;
        }else if(i != 1 && x > 1){
            a.push_back(x-1);
            x = 1;
        }else if(i != 1 && x == 1){
            a.push_back(0);
        }else a.push_back(x);
    }
    for(ll i = m-1; i >= 0; i--){
        cout << a[i];
    } cout << " ";
    x = s;
    for(ll i = 0; i < m; i++){
        if(x >= 9){
            cout << 9;
            x -= 9;
        }else{
            cout << x;
            x = 0;
        }
    }cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}