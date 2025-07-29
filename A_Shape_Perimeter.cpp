#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, m;
    cin >> n >>m;
    vi x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    ll sum = 0;
    for(int i = 1; i < n; i++){
        sum += 2*((m-x[i]) + (m-y[i]));
    }
    int z = n*4*m;
    cout << z-sum << endl;
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