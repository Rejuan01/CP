#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<string> s;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    //vector<vector<int>> visited(n, vector<int>(n, 0));
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < s[i].size()-1; j++){
            if(s[i][j] == '#'){
                if(s[i-1][j] == '#' && s[i][j-1] == '#' && s[i+1][j] == '#' && s[i][j+1] == '#'){
                    s[i][j] = '.';
                    s[i+1][j] = '.';
                    s[i-1][j] = '.';
                    s[i][j+1] = '.';
                    s[i][j-1] = '.';
                }
            } 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < s[i].size(); j++){
            if(s[i][j] == '#'){
                cout << "NO" << endl;
                return 0;
            } 
        }
    }
    cout << "YES" << endl;

}