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
    ll x = n, c1 = 0, c2 = 0, k = 1;
    while(x%5 == 0){
        x /= 5;
        c1++;
    }
    while(x%2 == 0){
        x /= 2;
        c2++;
    }
    while(c1 < c2 && k*5 <= m){
        c1++;
        k *= 5;
    }
    while(c2 < c1 && k*2 <= m){ // else
        c2++;
        k *= 2;
    }
    while(k*10 <= m) k*=10;
    k *= (m/k);
    cout << n*k << endl;
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