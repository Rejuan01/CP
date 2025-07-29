#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n);
        x[0] = 0; // not necessary
        for(int i = 1; i < n; i++){
            cin >> x[i];
        }
        vector<int> a;
        a.push_back(x[1]+1);
        for(int i = 1; i < n-1; i++){
            if(x[i] >= x[i+1]){
                a.push_back(a[i-1]+x[i]);
                continue;
            }
            int y = (x[i+1]-x[i])/a[i-1] + 1;
            a.push_back(y*a[i-1]+x[i]);
        }
        a.push_back(a[n-2]+x[n-1]);
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}