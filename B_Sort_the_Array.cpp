#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll i = 0, j = n-1;
    while(i < n-1 && a[i] <= a[i+1]){
        i++;
    }
    if(i == n-1){
        yes;
        cout << "1 1" << endl; return;
    }
    while(j >= 0 && a[j-1] <= a[j]){
        j--;
    }
    if(i > 0 && a[i-1] > a[j]){
        no; return;
    }
    if(j < n-1 && a[i] > a[j+1]){
        no; return;
    }
    bool flag = is_sorted(a.begin()+i, a.begin()+j, greater<ll>());
    if(flag){
        yes;
        cout << i+1 << " " << j+1 << endl;
    }else{
        no;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}