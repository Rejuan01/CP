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
    set<ll> stA, stB;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        stA.insert(temp);
    }
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        stB.insert(temp);
    }
    if(stA.size()*stB.size() >= 3){
        yes;
    }else{
        no;
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