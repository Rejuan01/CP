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
    string s;
    cin >> n >> s;
    stack<pair<char, ll>> stk;
    vi ans(n);
    set<ll> aa;
    for(ll i = 0; i < n; i++){
        if(stk.empty()){
            stk.push({s[i], i}); continue;
        }
        char b = stk.top().first;
        if(b == '(' && s[i] == ')'){
            ll idx = stk.top().second;
            ans[idx] = 1;
            ans[i] = 1;
            aa.insert(1);
            stk.pop();
        }else if(b == ')' && s[i] == '('){
            ll idx = stk.top().second;
            ans[idx] = 2;
            ans[i] = 2;
            aa.insert(2);
            stk.pop();
        }else{
            stk.push({s[i], i});
        }
    }
    if(!stk.empty()){
        cout << -1 << endl; return;
    }
    cout << aa.size() << endl;
    if(aa.size() == 1){
        ll x = n;
        while(x--){
            cout << 1 << " ";
        } cout << endl;
        return;
    }
    for(auto it: ans){
        cout << it << " ";
    } cout << endl;
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