#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
vi ans;
ll c;
void evenAns(ll x){
    c = 0;
    ll k = x;
    while(k){
        k >>= 1;
        c++;
    }c--;
    if(x == 4){
        ans = {2, 1, 3, 4}; return;
    }
    if(x == 6){
        ans = {1, 2, 4, 6, 5, 3}; return;
    }
    ans.push_back(2);
    for(ll i = 4; i < ((1<<c) - 2); i++) ans.push_back(i);
    for(ll i = ((1<<c)+1); i <= x; i++) ans.push_back(i);
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back((1<<c) - 2);
    ans.push_back((1<<c) - 1);
    ans.push_back(1<<c);
}
void solve(){
    ll n;
    cin >> n;
    if(n%2 == 0){
        evenAns(n);
        cout << (1<<(c+1))-1 << endl;
    }else{
        evenAns(n-1);
        ans.push_back(n);
        cout << n << endl;
    }
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
    ans.clear();
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