#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    unordered_set<char> st; // to see if already pushed into result vector
    vector<int> result; // to push distinct value according the sequence of s
    for(int i = 0; i < s.size(); i++){
        if(st.find(s[i]) == st.end()){ // character not inserted yet
            st.insert(s[i]);
            result.push_back(s[i]);
        }
    }
    char ch = 'a';
    for(int i = 0; i < result.size(); i++){ // result must hold values is this way "abcdefg...."
        if(result[i] != ch+i){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}