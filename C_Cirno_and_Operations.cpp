#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    ll sum  = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    while(a.size() > 1){
        ll x = abs(a[a.size()-1] - a[0]);
        sum = max(sum, x);
        vi b, c;
        ll sum1 = 0, sum2 = 0;
        for(ll j = 0; j < a.size()-1; j++){
            b.push_back(a[j+1] - a[j]);
            c.push_back(a[j]-a[j+1]);
        }
        a.clear();
        if(a[a.size()-1] >= a[0]){
            a = b;
        }else{
            a = c;
        }
    }
    sum = max(sum, a[0]);
    cout << sum << endl;
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