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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll i = 0, j = s.size()-1;
    ll p = 0;
    while(p+1 < s.size() && s[p] == s[p+1]) p++;
    if(p+1 == s.size()){
        no; return;
    }
    while(i < j && s[i] == s[j]){
        i++; j--;
    }
    if(i >= j){
        if(k == 0){
            no; return;
        }else{
            yes; return;
        }
    }
    if(k != 0 || s[i] < s[j]){
        yes; return;
    }else{
        no; return;
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