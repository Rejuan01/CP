#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int m1 = 0, m2 = 0, j = 0;
        int a[4];
        for(int i = 0; i < 4 ; i++){
            cin >> a[i];
        }
        m1 += a[0]; 
        m2 += a[0];
        j += a[0]; 
        while(1) {
            if((m1 == 0 && a[1] == 0) || (m2 == 0 && a[2] == 0) || (m1 == 0 && m2 == 0) || (a[1] == 0 && a[2] == 0)){
                break;
            }
            if(a[1] >= m2){
                a[1] -= m2;
                m1 += m2;
                j += m2;
                m2 = 0;
            }
            else if(a[1] < m2){
                m2 -= a[1];
                m1 += a[1];
                j += a[1];
                a[1] = 0;
            }
            if(a[2] >= m1){
                a[2] -= m1;
                m2 += m1;
                j += m1;
                m1 = 0;
            }
            else if(a[2] < m1){
                m1 -= a[2];
                m2 += a[2];
                j += a[2];
                a[2] = 0;
            }
        }
        if(m1 >= m2){
            if(a[3] > m2){
                j += (m2 + 1);
            }
            else if(a[3] <= m2 && a[3] != 0){
                j += (a[3] + 1);
            }
        }
        else if(m2 > m1){
            if(a[3] > m1){
                j += (m1 + 1);
            }
            else if(a[3] <= m1 && a[3] != 0){
                j += (a[3] + 1);
            }
        }
        cout << j << endl;;

    }
}