#include<iostream>
using namespace std;
int main(){ 
    int x,y;
    cin >> x;
    int a[x][x];
    int n = 1;
    int i = 0, j = 0, s = 1;
    int flag = 0;
    a[i][j] = 1;
    while(s != x){
        if(flag == 0){
            a[i][++j] = ++n;
            for(int t = 0; t < s; t++){
                a[++i][j] = ++n;
            }
            for(int t = 0; t < s; t++){
                a[i][--j] = ++n;
            }
            flag = 1;
        }
        else if(flag == 1){
            a[++i][j] = ++n;
            for(int t = 0; t < s; t++){
                a[i][++j] = ++n;
            }
            for(int t = 0; t < s; t++){
                a[--i][j] = ++n;
            }
            flag = 0;
        }
        s++;
    }
    //cout << a[x-1][y-1];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cout << a[i][j] << " ";
        }
    cout << endl;
    }
}