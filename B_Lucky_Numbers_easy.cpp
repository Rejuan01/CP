#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
ll cal(vi &num){
    ll n = num.size();
    ll x = num[0];
    for(ll i = 1; i < n; i++){
        x *= 10;
        x += num[i];
    }
    return x;
}
void solve(){
    ll n;
    cin >> n;
    ll x = n;
    ll s = 0;
    while(x){
        s++; 
        x/= 10;
    } s++; // handle odd size
    vi num(s/2, 4);
    for(ll i = 0; i < s/2; i++) num.push_back(7);
    vi b;
    b.push_back(cal(num));
    while(next_permutation(num.begin(), num.end())){
        b.push_back(cal(num));
    }
    ll index = lower_bound(b.begin(), b.end(), n) - b.begin();
    if(index == b.size()){
        num.push_back(4); 
        num.push_back(7);
        sort(num.begin(), num.end());
        ll x = cal(num);
        cout << x << endl; return;
    }
    cout << b[index] << endl;
    
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