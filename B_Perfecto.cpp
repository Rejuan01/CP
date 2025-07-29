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
    ll k = n*(n+1)/2;
    ll p = sqrt(k);
    if(p*p == k){
        cout << -1 << endl;
        return;
    }
    ll sum = 0;
    vi a;
    for(ll i = 1; i <= n; i++){
        a.push_back(i);
    }
    for(ll i = 0; i < n; i++){
        ll x = sum + a[i];
        ll y = sqrt(x);
        if(y*y == x){
            swap(a[i], a[i+1]);
        }
        sum += a[i];
    }
    sum = 0;
    for(auto it: a){
        // sum += it;
        // ll y = sqrt(sum);
        // if(y*y == sum){
        //     cout << "Error" << it << endl;
        //     break;
        // }
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