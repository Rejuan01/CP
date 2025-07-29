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
    string s;
    cin >> n >> s;
    ll i = 0, j = n-1;
    while(i < j && s[i] == s[j]){
        i++; j--;
    }
    if(i >= j){
        cout << 0 << endl; return;
    }
    char c1 = s[i], c2 = s[j];
    ll p = i, q = j;
    ll ans1 = 0, ans2 = 0;
    bool flag1 = false, flag2 = false;
    while(i < j){ // removing c1
        if(s[i] == s[j]){
            i++; j--; continue;
        }
        if(s[i] == c1){
            i++; ans1++;
        }
        else if(s[j] == c1){
            j--; ans1++;
        }
        else{
            flag1 = true;
            break;
        }
    }
    i = p, j = q;
    while(i < j){ // removing c2
        if(s[i] == s[j]){
            i++; j--; continue;
        }
        if(s[i] == c2){
            i++; ans2++;
        }
        else if(s[j] == c2){
            j--; ans2++;
        }
        else{
            flag2 = true;
            break;
        }
    }
    if(flag1 && flag2){
        cout << -1 << endl;
    }else if((!flag1) && (!flag2)){
        cout << min(ans1, ans2) << endl;
    }else if(!flag1){
        cout << ans1 << endl;
    }else{
        cout << ans2 << endl;
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