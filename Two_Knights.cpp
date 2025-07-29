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
    for(ll k = 1; k <= n; k++){
        ll x = k*k;
        x = x*(x-1)/2; // x = xC2 possible combinations
        if(k < 3){
            cout << x << endl;
            continue;
        }
        ll y = 4*(k-1)*(k-2); // possible combinations to attack each other
        cout << x-y << endl;
    }
}
// in a 3X2 box, two possible combinations
// in a 2x3 box, two possible combinations
// number of 3x2 boxes, (n-1)(n-2)
// number of 2x3 boxes, (n-1)(n-2)
// total combinations to attack = 2*2*(n-1)*(n-2)
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