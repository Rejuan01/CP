#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
int main(){
    int t;
    cin >> t;
    while(t--){
        lli w, h;
        cin >> w >> h;
        lli k, x1, x2, x11, x12, y1, y2, y11, y12;
        cin >> k;
        for(int i = 0; i < k; i++){
            int p;
            cin >> p;
            if(i == 0) x1 = p; // ignoring all, just taking first and last value to maximize the base
            else if(i == k-1) x2 = p;
        } cin >> k;
        for(int i = 0; i < k; i++){
            int p;
            cin >> p;
            if(i == 0) x11 = p;
            else if(i == k-1) x12 = p;
        } cin >> k;
        for(int i = 0; i < k; i++){
            int p;
            cin >> p;
            if(i == 0) y1 = p;
            else if(i == k-1) y2 = p;
        } cin >> k;
        for(int i = 0; i < k; i++){
            int p;
            cin >> p;
            if(i == 0) y11 = p;
            else if(i == k-1) y12 = p;
        }
        vector<lli> ans; // 4 possible max value
        ans.push_back((x2-x1)*h); 
        ans.push_back((x12-x11)*h);
        ans.push_back((y2-y1)*w);
        ans.push_back((y12-y11)*w);
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
}