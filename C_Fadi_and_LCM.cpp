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
    a.push_back(1);
    a.push_back(n);
    for(ll i = 2; i*i <= n; i++){ // divisors
        if(n%i == 0){
            a.push_back(i);
            a.push_back(n/i);
        }
    }
    sort(a.begin(), a.end());
    // for(auto it: a){
    //     cout << it << " ";
    // } cout << endl;
    for(ll i = 0; i < a.size(); i++){
        for(ll j = 0; j <= i; j++){
            if(lcm(a[i], a[j]) == n){
                cout << a[j] << " " << a[i] << endl;
                return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}