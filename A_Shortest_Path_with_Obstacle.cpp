#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    cin.ignore();
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 == x2){
        ll r = abs(y1-y2);
        if(x3 == x1) {
            if((y3 > y1 && y3 < y2) || (y3 > y2 && y3 < y1)) r+=2;
        }
        cout << r << endl;
        return;
    }
    if(y1 == y2){
        ll r = abs(x1-x2);
        if(y3 == y1) {
            if((x3 > x1 && x3 < x2) || (x3 > x2 && x3 < x1)) r+=2;
        }
        cout << r << endl;
        return;
    }
    cout << abs(y1-y2)+abs(x1-x2) << endl;
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