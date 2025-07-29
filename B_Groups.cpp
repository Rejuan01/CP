#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> vct(n, vector<int>(5));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                cin >> vct[i][j];
            }
        }
        bool flag = true;
        for(int i = 0; i < 5 && flag; i++){
            for(int j = i+1; j < 5 && flag; j++){
                int count1 = 0;
                int count2 = 0;
                int common = 0;
                for(int k = 0; k < n; k++){
                    if(vct[k][i])
                        count1++;
                    if(vct[k][j])
                        count2++;
                    if(vct[k][i] && vct[k][j])
                        common++;
                }
                if(count1 >= n/2 && count2 >= n/2 && count1+count2-common==n){
                    cout << "YES" << endl;
                    flag = false;
                }
            }
        }
        if(flag){
            cout << "NO" << endl;
        }
    }
}