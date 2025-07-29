#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int m1 = m;
        int m2 = m;
        int total = 0;
        if(a >= m){
            total += m;
            m1 = 0;
        }
        else{
            total += a;
            m1 -= a;
        }
        if(b >= m){
            total += m;
            m2 = 0;
        }
        else{
            total += b;
            m2 -= b;
        }
        if(m1+m2 >= c){
            total += c;
        }
        else{
            total += (m1+m2);
        }
        cout << total << endl;
        
    }
}