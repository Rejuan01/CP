#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
void solve(ll tc){
    ll n, l, r;
    cin >> n >> l >> r;
    vi a(n+1), b(n+1);
    for(ll i = 0; i <= n; i++) a[i] = i;
    a[l-1] = r;

    for(ll i = n; i > 0; i--)  
        b[i] = a[i]^a[i-1];

    for(ll i = 1; i <= n; i++) 
        cout << b[i] << " ";

    cout << endl;
}
int main(){
    int tc;
    cin >> tc;
    for(ll i = 1; i <= tc; i++) solve(tc);
    return 0;
}