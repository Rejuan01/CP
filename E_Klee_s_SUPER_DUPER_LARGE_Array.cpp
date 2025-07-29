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
    ll s = n*(n-1)/2 + n*k;
    //cout << s << endl;
    ll l = 1, r = n;
    while(l+1 < r){ // l and r both going toward lower abs difference (answer). l -> negative or zero difference, r -> positive difference
        ll m = (l+r)/2;
        ll x = m*(m-1)/2 + m*k;
        ll y = s-x;
        if(x > y){
            r = m;
        }else{
            l = m;
        }
    }
    ll x1 = l*(l-1)/2 + l*k;
    x1 = abs(s-2*x1);
    ll x2 = r*(r-1)/2 + r*k;
    x2 = abs(s-2*x2);
    cout << min(x1, x2) << endl;
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