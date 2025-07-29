#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    bool flag = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            if(!flag && temp && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                flag = true; // if just a single '1' in the outer boundery line, needs 2 steps else 4
            }
        }
    }
    if(flag){
        cout << 2 << endl;
    }
    else{
        cout << 4 << endl;
    }
}