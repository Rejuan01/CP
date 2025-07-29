#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        int a[n][n-1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-1; j++){
                cin >> a[i][j];
            }
        }

        int pointer; // the row where first value is missing
        int temp ;   // actual first value of real premutation
        if(a[0][0] == a[1][0]){
            temp = a[0][0];
            for(int i = 2; i < n; i++){
                if(a[i][0] != temp){
                    pointer = i;
                    break;
                } 
            }
        }
        else if(a[0][0] == a[2][0]){
            pointer = 1;
            temp = a[0][0];
        }
        else{  //a[1][0] == a[2][0]
            pointer = 0;
            temp = a[1][0];
        }
        cout << temp << " ";
        for(int i = 0; i < n-1; i++){
            cout << a[pointer][i] << " ";
        }
        cout << endl;
    }

    return 0;
}