#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> y(m);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }
    int ptrx = 0, ptry = 0;
    int countX = x[0], countY = y[0];
    int c = 0;
    while(ptrx < n && ptry < m){
        while(countX < countY){
            ptrx++;
            countX += x[ptrx];
        }
        while(countX > countY){
            ptry++;
            countY += y[ptry];
        }
        if(countX == countY){
            c++;
            ptrx++;
            ptry++;
            if(ptrx < n){ // if ptrx != n then always ptry != m
                countX = x[ptrx];
                countY = y[ptry];
            }
        }
    }
    cout << c << endl;
}