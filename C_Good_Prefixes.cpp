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
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll count = 0, sum = 0;
    set<ll> st;
    for(ll i = 0; i < n; i++){
        sum += a[i];
        st.insert(a[i]);
        if(sum%2 == 0 && st.find(sum/2) != st.end()){
            count++;
        }
    }
    cout << count << endl;
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