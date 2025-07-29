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
    string s;
    cin >> s;
    vi a, b;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'A'){
            a.push_back(i+1);
        }else{
            b.push_back(i+1);
        }
    }
    bool flag = true;
    for(auto it: a){
        if(it == n && b.front() == 1) continue;
        ll idx = lower_bound(b.begin(), b.end(), it) - b.begin();
        if(idx == b.size() || (it == 1 && b[idx] == n) ){ // if there atleast one card of alice which cannot be taken by bob
            cout << "Alice" << endl; 
            return;
        }
    }
    cout << "Bob" << endl;
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