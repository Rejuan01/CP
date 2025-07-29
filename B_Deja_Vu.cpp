#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n, q;
    cin >> n >> q;
    vi x, a;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(ll i = 0; i < q; i++){
        ll temp;
        cin >> temp;
        x.push_back(pow(2, temp));
    }
    ll d = x[0];
    for(ll i = 0; i < q; i++){
        if(x[i] > d) continue;   // higher power value grater than d will not work
        ll j = 0; 
        for(; j < n; j++){
            if(a[j] % x[i] == 0){
                a[j] += x[i]/2;
            }
        }
        d /= 2;  // after adding 2^(x[i]-1), values are only divisible by 2^(x[i]-1) or lower power
    }
    for(auto &it : a){
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