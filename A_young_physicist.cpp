#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int f[n][3];
    int sum[3] = {0};
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < 3; j++){
            cin >> f[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < n; k++){
            sum[i] += f[k][i];
        }
    }
    if( sum[0] == 0 && sum[1] == 0 && sum[2] == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}