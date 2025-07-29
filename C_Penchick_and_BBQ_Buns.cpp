#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    if(n%2 == 0){
        for(ll i = 0; i < n/2; i++){
            cout << i+1 << " " << i+1 << " ";
        }cout << endl;
        return;
    }
    if(n < 27){
        cout << -1 << endl; return;
    }
    cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12 ";
    n -= 27;
    n /= 2;
    ll x = 14;
    while(n--){
        cout << x << " " << x << " ";
        x++;
    } cout << endl;
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}