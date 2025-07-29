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
    vi a;
    for(ll i = 1;; i++){
        ll k = i*(i+1)/2;
        if(k < n){
            a.push_back(k);
        }else break;
    }
    for(ll i = 0; i < a.size(); i++){
        ll index = lower_bound(a.begin(), a.end(), n-a[i]) - a.begin();
        if(index == a.size() || a[index] + a[i] != n) continue;
        else{
            yes;
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
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}