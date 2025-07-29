#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char str[n][m];
        int whiteCount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> str[i][j];
                if(str[i][j] == '.'){
                    whiteCount++;
                }
            }
        }
        if(2*x <= y){
            cout << whiteCount*x << endl;
            continue;
        }
        int cost = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j < m-1 && str[i][j] == '.' && str[i][j+1] == '.'){
                    cost += y;
                    j++;
                }
                else if(str[i][j] == '.'){
                    cost += x;
                }
            }
        }
        cout << cost << endl;

    }
}