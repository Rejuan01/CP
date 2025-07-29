#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, k;
    cin >> n >> k;
    ll y = 0;
    for(ll i = 0; i < n; i++){
        cout << (y^i) << endl; // 0^0, 0^1, 1^2... (x-1)^x (then return)
        //cout.flush();
        ll r;
        cin >> r;
        if(r) return;
        y = i;
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