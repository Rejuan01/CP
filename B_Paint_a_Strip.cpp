#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }else if(n < 5){
        cout << 2 << endl;
        return;
    }
    int steps = 3;
    int ptr = 3;  // l=0, r= ptr
    while(1){
        ptr = (ptr+2)*2-1; // count is already ptr+1, one more stripe added. So, max range covered is (ptr+2)*2
        if(ptr >= n-1) break;
        steps++;
    }
    cout << steps << endl;
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