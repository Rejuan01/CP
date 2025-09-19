#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
    ll lc = 0, cc = 0, tc = 0, lcc = 0, ctc = 0, lctc = 0;
    for(auto &ch: s){
        if(ch == 'L') lc++;
        else if(ch == 'C'){
            cc++;
            lcc += lc;
        }
        else if(ch == 'T'){
            tc++;
            ctc += cc;
            lctc += lcc;
        }
    }
    ll m = max(lcc, ctc);
    ll x = 0, y = 0;
    for(auto &ch: s){
        if(ch == 'L') x++;
        else if(ch == 'T') y++;
        m = max(m, x*(tc-y));
    }
    cout << lctc+m << endl; return 0;
}
