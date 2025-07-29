#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl 
void solve(){
    ll n;
    cin>> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] == 1) {yes; return;}
    int p1 = 0, p2 = 1;
    while(p2 < n-1 && a[p2] % a[p1] == 0) p2++;
    if(p2 == n-1) {yes; return;}
    for(int i = p2; i < n; i++){
        if(a[i]%a[p1] && a[i]%a[p2]){
            no; return;
        }
    }
    yes;
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