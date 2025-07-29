#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define alice cout<<"Alice"<<endl
#define bob cout<<"Bob"<<endl 
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int i;
    for(i = 0; i < n && a[i]==b[i]; i++); // a == b
    if(i == n){
        bob;
        return;
    }
    for(i = 0; i < n && a[i]==b[n-i-1]; i++); // a is reverse of b
    if(i == n){
        bob;
        return;
    }
    alice;
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