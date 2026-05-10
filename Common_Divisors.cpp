#include<bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<ll>;
const ll N = 1e6+5;
ll c[N];
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]]++;
    }
    for(ll i = N-1; i > 0; i--){
        ll cnt = 0;             // How many numbers in a[] are divisible by i
        for(ll j = i; j < N; j += i){
            cnt += c[j];
        }
        if(cnt > 1){            
            cout << i << endl;
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}