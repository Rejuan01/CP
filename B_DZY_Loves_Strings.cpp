#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;
    vector<int> a(26);
    for(int i = 0; i < 26; i++){
        cin >> a[i];
    }
    int maxVal = *max_element(a.begin(), a.end());
    int sum = 0;
    int i;
    for(i = 0; i < s.size(); i++){
        sum += (i+1)*a[s[i]-'a'];
    }
    while(k--){
        sum += (i+1)*maxVal;
        i++;
    }
    cout << sum << endl;
}