#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;   // trailing zeros of n! will be the output
    int a, k;
    int c=0, c1=0, c2=0;
    k = n;
    while(k/2 != 0){
        k = k/2;
        c1 += k;
    }
    k = n;
    while(k/2 != 0){
        k = k/5;
        c2 += k;
    }
    k = n;
    while(k/10 != 0){
        k = k/10;
        c += k;
    }
    c1 -= c;
    c2 -= c;
    if(c1 > c2){
        c = c+c2;
    }
    else{
        c = c+c1;
    }
    //cout << c1 << " " << c2 << " " << c << endl;
    cout << c << endl;
}