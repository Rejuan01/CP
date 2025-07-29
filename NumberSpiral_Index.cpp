#include<iostream>
using namespace std;
int main(){ 
    long long int x;
    long long int r, c;
    long int T; cin >> T;
    for(long int ts = 0; ts < T; ts++){
    cin >> r >> c;
    if(r>c){x = r; }
    else{x = c; }
    int n = 1;
    long long int a[x][x];
    long int i = 0, j = 0, s = 1;
    int flag = 0;
    a[i][j] = 1;
    while(s != x){
        if(flag == 0){
            a[i][++j] = ++n;
            for(long long int t = 0; t < s; t++){
                a[++i][j] = ++n;
            }
            for(long long int t = 0; t < s; t++){
                a[i][--j] = ++n;
            }
            flag = 1;
        }
        else if(flag == 1){
            a[++i][j] = ++n;
            for(long long int t = 0; t < s; t++){
                a[i][++j] = ++n;
            }
            for(long long int t = 0; t < s; t++){
                a[--i][j] = ++n;
            }
            flag = 0;
        }
        s++;
    }
    cout << a[r-1][c-1] << endl;
    }
}