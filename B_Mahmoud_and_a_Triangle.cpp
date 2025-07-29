#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            if(a[i] + a[j] > a[j+1]){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}