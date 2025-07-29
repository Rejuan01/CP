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
    ll l = 2, r = 1e10;
    while(l+1 < r){ // find min different flavour needed
        ll m = (l+r)/2;
        if(n < m*(m-1)/2){ // mC2
            r = m;
        }else l = m;
    }
    l += n-l*(l-1)/2; // added duplicate falvour
    
    cout << l << endl;
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