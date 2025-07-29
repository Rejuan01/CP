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
    ll n, x;
    cin >> n >> x;
    vi a;
    for(ll i = 0; i < x; i++){
        a.push_back(i);
    }
    for(ll i = x+1; i < n; i++){
        a.push_back(i);
    }
    if(x < n){
        a.push_back(x);
    }
    for(auto it: a){
        cout << it << " ";
    }cout << endl;
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