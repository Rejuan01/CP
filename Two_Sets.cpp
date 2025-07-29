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
    set<ll> st1, st2;
    ll x = n%4;
    if(x == 1 || x == 2){ // sum will be odd
        no; return;
    }
    yes;
    ll i = 1, j = n;
    if(x == 3){
        st1.insert(1);
        st1.insert(2);
        st2.insert(3);
        i = 4;
    } // now remaining r multiple of 4
    while(i < j){
        st1.insert(i);
        st1.insert(j);
        st2.insert(i+1);
        st2.insert(j-1);
        i += 2;
        j -= 2;
    }
    cout << st1.size() << endl;
    for(auto &it: st1){
        cout << it << " ";
    } cout << endl;

    cout << st2.size() << endl;
    for(auto &it: st2){
        cout << it << " ";
    } cout << endl;
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