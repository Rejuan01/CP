#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int maxSum = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = i, y = j;
                int sum = a[x][y];
                while(x-1 >= 0 && y-1 >= 0){
                    sum += a[--x][--y];
                }
                x = i, y = j;
                while(x+1 < n && y+1 < m){
                    sum += a[++x][++y];
                }
                x = i, y = j;
                while(x-1 >= 0 && y+1 < m){
                    sum += a[--x][++y];
                }
                x = i, y = j;
                while(x+1 < n && y-1 >= 0){
                    sum += a[++x][--y];
                }
                maxSum = max(sum, maxSum);
            }
        }
        cout << maxSum << endl;

    }
}