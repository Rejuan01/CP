#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vector<ll> res;
    res.push_back(1);
    for(ll i = 1; i < n-1; i++){
        res.push_back(i);
    }
    res.push_back(1);
    for(auto it: res){
        cout << it << " ";
    } cout << endl;
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