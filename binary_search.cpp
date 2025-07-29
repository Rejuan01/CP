#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a = {5, 3, 8, 2, 1};
    sort(a.begin(), a.end());
    for(int i = 0; i < 5; i++){
        cout << a[i];
    }
    return 0;
}