#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << " " << 0 << endl;
        return;
    }
    ll x = min(a, b);
    ll y = max(a, b);
    ll z = y-x;
    y = x%z;
    if(z-y < y) y = z-y;
    cout << z << " " << y << endl;
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