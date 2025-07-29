#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        int minAbs = INT_MAX;
        int negCount = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = v[i][j];
                if(x < 0) negCount++;
                x = abs(x);
                sum += x;
                if(x < minAbs) minAbs = x;
            } 
        }
        if(negCount%2 == 0) cout << sum << endl;
        else cout << sum-2*minAbs << endl;
    }
}