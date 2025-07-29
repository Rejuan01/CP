#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, a;
    cin >> n >> m >> a;
    int x = n/a;
    int y = m/a;
    if(n%a != 0){
        x++;
    }
    if(m%a != 0){
        y++;
    }
    cout << 1LL*x*y << endl;
    return 0;
}