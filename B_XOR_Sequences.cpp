#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int x, y;
    cin >> x >> y;
    for(int bit = 0; bit < 31; bit++){    // find the n th bit not equal
        if(((x>>bit)&1) != ((y>>bit)&1)){
            cout << (1 << bit) << endl;   // result is 2^n
            return;
        }
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