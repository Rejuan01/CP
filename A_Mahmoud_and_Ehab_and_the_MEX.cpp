#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int count = 0;
    int i;
    for(i = 0; a[i] < x && i < n; i++){ // how many numbers less than x are present
        count++;
    }
    int steps = x-count; // need to be added
    
    if(a[i] == x){ // if x exists, that needs to be removed
        steps++;
    }
    cout << steps << endl;
}