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
    vi a;
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            a.push_back(i);
            if(i*i != n){
                a.push_back(n/i);
            }
        }
    }
    sort(a.begin(), a.end(), greater<ll>());
    for(auto i: a){
        ll x = n/i;
        ll y = i*x*(x-1)/2 + x;
        cout << y << " ";
    } cout << endl;
}
/*
Loop will go till lcm(n, k). Means lcm(n, k)/n times. OR k/gcd(n, k) times
So, for every k, we get indeces that are the multiples of GCD(n, k) which are divisors of n.
So, the result is for all the divisors of n
*/
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
       solve();
    }
    return 0;
}