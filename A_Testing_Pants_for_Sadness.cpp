#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long int count = a[0];
    for(int i = 1; i < n; i++){
        count++;
        count += (a[i]-1)*(i+1);
    }
    cout << count << endl;
}