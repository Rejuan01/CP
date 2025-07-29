#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //vector<int> a(n);
        vector<int> s(1001, -1);
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            s[temp] = i+1; // storing latest(largest by overriding) index
        }
        int res = -1;
        bool flag = true;
        for(int i = 1; i < s.size(); i++){
            for(int j = i; (s[i]+1) && j < s.size(); j++){ // if s[i] == -1 continue;
                if((s[j]+1) && gcd(i, j) == 1 && s[i]+s[j] > res){ // if s[j] == -1 continue;
                    res = s[i]+s[j];
                }
            }
        }
        cout << res << endl;
    }
}