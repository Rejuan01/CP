#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end(), greater<int>());
    int count = 0;
    for(int i = 0; i < n; i++){
        int x = (d+1)/p[i];
        if((d+1)%p[i] != 0) x++;
        if(i+x-1 < n) count++;
        n -= (x-1);
    }
    cout << count << endl;
}