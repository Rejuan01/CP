#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1); // dp[i] = min steps require for i to reach zero 
    for(int i = 1; i <= n; i++){
        int x = i;
        int m = 1e9;
        while(x){
            if(x%10) 
                m = min(m, dp[i-x%10]);
            x /= 10;
        }
        dp[i] = m+1;
    }
    cout << dp[n] << endl;
    return 0;
}
