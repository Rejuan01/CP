#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
       
        for(int i = 1; i < n; i++){
            if(a[i-1] > b[i]){
                count += (a[i-1] - b[i]);
            }
        }
        count += a[n-1];
        cout << count << endl;

    }
}