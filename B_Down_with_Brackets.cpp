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
    string s;
    cin >> s;
    stack<ll> stk;
    for(ll i = 1; i < s.size()-1; i++){
        if(!stk.empty() && s[i] == ')' && stk.top() == '('){
            stk.pop();
        }else stk.push(s[i]);
    }
    if(stk.empty()){
        no;
    }else yes;
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