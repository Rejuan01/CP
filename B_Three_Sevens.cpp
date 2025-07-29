#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        vector<vector<int>> a; 
        for(int i = 0; i < m; i++){
            int n;
            cin >> n;
            vector<int> temp(n); // row
            for(int j = 0; j < n; j++){
                int t;
                cin >> t;
                temp[j] = t;
            }
            a.push_back(temp);
        }
        bool flag = false;
        stack<int> winner;
        unordered_set<int> pl; // participated later
        for(int i = m-1; i >= 0; i--){
            int w = -1;
            for(int j = 0; j < a[i].size(); j++){
                if(w == -1 && pl.find(a[i][j]) == pl.end()){ // winner not found yet and a[i][j] did not perticipated later then this is probable the winner
                    w = a[i][j];
                }
                pl.insert(a[i][j]); 
            }
            if(w == -1){ // all perticipated before
                cout << -1 << endl;
                flag = true;
                break;
            }
            winner.push(w);
        }
        if(!flag){
            while(!winner.empty()){
                cout << winner.top() << " ";
                winner.pop();
            }
            cout << endl;
        }
    }
}