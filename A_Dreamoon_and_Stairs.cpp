#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    if (n < m){
        cout << "-1" << endl;
        return 0;
    }
    int k;
    for(k = m; 2*k < n; k+=m);
    cout << k << endl;
    return 0;
}