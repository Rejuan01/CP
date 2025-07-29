#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> board(8);
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    bool flag = true;
    for(int i = 0; i < 8 && flag; i++){
        for(int j = 0; j < 7; j++){
            if(board[i][j] == board[i][j+1]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}