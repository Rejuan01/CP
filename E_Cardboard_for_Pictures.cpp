#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, c;
    cin >> n >> c;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 1, h = 1e9;
    while(l <= h){
        ll m = (l+h)/2;
        ll area = 0;
        for(ll i = 0; i < n; i++){
            area += (a[i] + 2*m)*(a[i] + 2*m);
            if(area > c) break;
        }
        if(area > c) h = m-1;
        else if(area < c) l = m+1;
        else{ // area == c
            cout << m << endl;
            return;
        }
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