#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    int l[n], r[n];
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    int currentTime = 1;
    int time = 0;
    for(int i = 0; i < n; i++){
        while(currentTime + x <= l[i]){
            currentTime += x;
        }
        time += (l[i] - currentTime);
        time += (r[i] - l[i] + 1);
        currentTime = r[i]+1;
    }
    cout << time << endl;
    
}