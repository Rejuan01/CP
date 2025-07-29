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
    vi a(n), b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    vi x, y;
    for(ll i = 0; i < n; i++){
        if(b[i] > a[i]){
            x.push_back(b[i]-a[i]);
        }else{
            y.push_back(a[i]-b[i]);
        }
    }
    if(x.empty()){
        yes; return;
    }
    if(x.size() > 1 || y.empty()){
        no; return;
    }
    int k = *min_element(y.begin(), y.end());
    if(x[0] > k){
        no;
    }else{
        yes;
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