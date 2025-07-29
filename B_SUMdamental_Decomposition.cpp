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
    ll n, x;
    cin >> n >> x;
    if(x == 0){
        if(n%2 == 0){
            cout << n << endl; 
        }
        else if(n == 1){
            cout << -1 << endl;
        }else cout << n+3 << endl; // n-1 + 4
        return;
    }
    if(x == 1){
        if(n%2 == 0){
            cout << n+3 << endl;
        }else{
            cout << n << endl;
        } return;
    }
    ll k = x;
    ll c = 0;
    while(k){
        if(k&1) c++;
        k >>= 1;
    } c--;
    
    ll ans = x;
    if(x%2 == 0){
        if(n%2){
            ans += (n-1);
            ans -= min((c/2)*2, ((n-1)/2)*2);
        }else{
            ans += n;
            c++;
            ans -= min((c/2)*2, (n/2)*2);
        }
        cout << ans << endl; return;
    }
    else{
        if(n%2){
            ans += n-1;
            ans -= min((c/2)*2, (n/2)*2);
        }else{
            ans += n-2;
            c--;
            ans -= min((c/2)*2, ((n-1)/2)*2);
        }
        cout << ans << endl;
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