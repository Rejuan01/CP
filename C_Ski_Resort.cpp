#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        lli count = 0;
        vector<int> v;
        for(int i = 0; i < n; i++){
            int temp; 
            cin >> temp;
            if(temp <= q){ // number of continuous days in expected temperature range
                count++;
            }
            if(temp > q || i == n-1){
                if(count >= k){
                    v.push_back(count);
                }
                count = 0;
            }
        }
        for(int it : v){
            lli x = it-k+1;
            x = x*(x+1)/2; // number of ways to visit for minimum 'k' days within 'it' days
            count += x; // resusing count var to store number of ways
        }
        cout << count << endl; 
    }
}