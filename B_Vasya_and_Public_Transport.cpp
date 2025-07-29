#include<bits/stdc++.h>
using namespace std;
int main(){
    int c[4];
    for(int i = 0; i < 4; i++){
        cin >> c[i];
    }
    int n, m;
    cin >> n >> m;
    int b[n], t[m];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    int costB = 0, costT = 0;
    for(int i = 0; i < n; i++){
        if(b[i]*c[0] <= c[1]){
            costB += b[i]*c[0];
        }
        else{
            costB += c[1];
        }
    }
    if(costB > c[2]){
        costB = c[2];
        
    }
    for(int i = 0; i < m; i++){
        if(t[i]*c[0] <= c[1]){
            costT += t[i]*c[0];
        }
        else{
            costT += c[1];
        }
    }
    if(costT > c[2]){
        costT = c[2];
    }
    if(costB+costT > c[3]){
        cout << c[3] << endl;
    }
    else{
        cout << costB+costT << endl;
    }

}