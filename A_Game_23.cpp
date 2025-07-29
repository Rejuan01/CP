#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if(m % n != 0){
        cout << -1 << endl;
        return 0;
    }
    int k = m/n;
    int steps = 0;
    while(k){
        if(k % 3 == 0){
            k /= 3;
            steps++ ;
        }
        else if(k % 2 == 0){
            k /= 2;
            steps++ ;
        }
        else{
            break;
        }
    }
    if(k == 0 || k == 1){
        cout << steps << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}