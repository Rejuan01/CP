#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), DP(x+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    DP[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int &c: a){
            if(i >= c) DP[i] = (DP[i] + DP[i-c])%mod;
        }
    }
    cout << DP[x] << endl;
}