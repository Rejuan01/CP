#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ptr;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == n){
            ptr = i;
        }
    }
    if(is_sorted(a.begin()+ptr, a.end(), greater<int>()) && is_sorted(a.begin(), a.begin()+ptr)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
}