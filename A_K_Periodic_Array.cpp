#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int changes = 0;
    for(int i = 0; i < k; i++){
        int countOne = 0;
        int countTwo = 0;
        for(int j = i; j < n; j += k){
            if(a[j] == 1){
                countOne++;
            }
            else{
                countTwo++;
            }
        }
        changes += min(countOne, countTwo);
    }
    cout << changes << endl;
}