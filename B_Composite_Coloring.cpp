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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi c = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    ll id = 0;
    for(auto i: c){
        bool flag = false;
        for(auto &it: a){
            if(it%i == 0){
                it = id+1;
                flag = true;
            }
        }
        if(flag) id++;
    }
    cout << id << endl;
    for(auto it: a){
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