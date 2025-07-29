#include<bits/stdc++.h>
using namespace std;
int main(){
    int k = 1; //initial house
    int n, m;
    long long int sum = 0; // total time required
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        if(k <= a[i]){
            sum += (a[i] - k);
            k = a[i];
        }
        else{
            sum += (n - (k - a[i]));
            k = a[i];
        }
    }
    cout << sum << endl;
}