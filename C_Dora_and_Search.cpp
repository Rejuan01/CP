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
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll min = 1, max = n;
    ll i = 0, j = n-1;
    while(i < j){
        bool flag1 = true, flag2 = true;
        if(a[i] == min){
            i++; min++; 
            flag1 = false;
        }else if(a[i] == max){
            i++; max--;
            flag1 = false;
        }
        if(a[j] == min){
            j--; min++;
            flag2 = false;
        }else if(a[j] == max){
            j--; max--;
            flag2 = false;
        }
        if(flag1 && flag2){
            cout << i+1 << " " << j+1<< endl;
            return;
        }
    }
    cout << -1 << endl;
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