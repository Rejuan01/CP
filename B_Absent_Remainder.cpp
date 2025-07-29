#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            a[i] = temp;
            s.insert(temp);
        }
        sort(a.begin(), a.end());
        int count = 0;
        for(int i = 0; i < n-1 && count < n/2; i++){
            for(int j = i+1; j < n && count < n/2; j++){
                int temp = a[j] % a[i];
                if(s.find(temp) == s.end() && count < n/2){
                    cout << a[j] << " " << a[i] << endl;
                    count++;
                }
            }
        }
    }
}