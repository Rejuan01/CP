#include<iostream>
using namespace std;
void first(void);
void second(void);
#define x 5
int a[x][x];
int n = 1, i = 0, j = 0, s = 1;
void first(){
    if(s == x){return;}
    a[i][++j] = ++n;
    for(int t = 0; t < s; t++){
        a[++i][j] = ++n;
    }
    for(int t = 0; t < s; t++){
        a[i][--j] = ++n;
    }
    s++;
    second();
}
void second(){
    if(s == x){return; }
    a[++i][j] = ++n;
    for(int t = 0; t < s; t++){
        a[i][++j] = ++n;
    }
    for(int t = 0; t < s; t++){
        a[--i][j] = ++n;
    }
    s++;
    first();
}
int main(){
    a[0][0] = n;
    first();
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}