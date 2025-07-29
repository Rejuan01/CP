#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    cin >> a[0];
    ll sum = a[0];
    ll res = a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(abs(a[i]%2) != abs(a[i-1]%2)){ // opposite parity
            sum += a[i];
            if(sum < a[i]) sum = a[i];    // handle some negative value
        }else{
            sum = a[i]; // restart adding
        }
        res = max(res, sum);
    }
    res = max(res, sum);
    cout << res << endl;
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