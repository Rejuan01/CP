#include<bits/stdc++.h>
using namespace std;
void solve(){
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size()){
        string temp = a;
        a = b;
        b = temp;
    }
    int ans = a.size()+b.size(); // delete all and get two empty string
    bool flag = true;
    for(int i = 0; i < a.size() && flag; i++){
        int len = a.size()-i; // the length of substring I will search for
        for(int j = 0; j+len <= a.size() && flag; j++){
            string sub = a.substr(j, len);
            auto p = b.find(sub);
            if(p != string::npos){
                ans = i+b.size()-len; // i = char need to delete from a, b.size()-len = the number of char need to delete from b
                flag = false;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}