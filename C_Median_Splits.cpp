#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
bool check1(vi &b, ll k){
    ll n = b.size();
    ll l = 0, c1 = 0;
    bool flag1 = false, flag2 = false;
    while(l < n-2){
        if(b[l] <= k) c1++;
        if(c1 >= (l+2)/2){
            flag1 = true;
            break;
        }
        l++;
    }
    //cout << l << endl;
    if(l+1 < n-2 && b[l+1] > k && l%2 == 0)l++;
    ll r = l+1, c2 = 0;
    while(r < n-1){
        if(b[r] <= k) c2++;
        if(c2 >= (r-l+1)/2){
            flag2 = true;
            break;
        }
        r++;
    }
    // cout << flag1 << " " << flag2 << endl << endl;
    // cout << c2 << " " << r << endl;
    if(flag1 && flag2){
        // cout << c1 << " " << c2 << endl;
        // cout << l << " " << r << endl;
        cout << "YES" << endl;
        return true;
    } 
    return false;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vi a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vi b = a;
    if(check1(b, k)) return;
    reverse(b.begin(), b.end());
    if(check1(b, k)) return;
    
    ll l = 0, c1 = 0;
    bool flag1 = false, flag2 = false;
    while(l < n-2){
        if(a[l] <= k) c1++;
        if(c1 >= (l+2)/2){
            flag1 = true;
            break;
        }
        l++;
    }
    ll r = n-1, c2 = 0;
    while(l+1 < r){
        if(a[r] <= k) c2++;
        if(c2 >= (r-l+1)/2){
            flag2 = true;
            break;
        }
        r--;
    }
    if(flag1 && flag2){
        yes; 
        return;
    }
    no;
    
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