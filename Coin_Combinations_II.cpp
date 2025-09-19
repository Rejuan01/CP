#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> c(n+1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    // vector<vector<int>> dp(n+1, vector<int>(x+1));
    // dp[i][j] = how many ways to get sum j from first i coins
    vector<int> prev(x+1); // dp[i-1]
    for(int i = 1; i <= n; i++){
        vector<int> current(x+1); // dp[i]
        // dp[i][0] = 1; 
        current[0] = 1;
        for(int j = 1; j <= x; j++){
            if(c[i] > j){
                current[j] = prev[j]; continue;
            }
            current[j] = prev[j] + current[j-c[i]];
            current[j] %= mod;
        }
        prev = current;
    }
    cout << prev[x] << endl;
}
