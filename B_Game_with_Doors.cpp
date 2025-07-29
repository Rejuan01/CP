#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<int>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int sum = 0;
    if(l2 > r1 || l1 > r2){
        cout << 1 << endl;
        return;
    }
    if(l1 < l2 && l2 <= r1 && r1 <= r2){
        sum += (r1-l2+1);
        if(r2 > r1) sum++;
    }else if(l2 <= l1 && l1 <= r2 && r2 < r1){
        sum += (r2-l1+1);
        if(l2 < l1) sum++;
    }else if(l2 <= l1 && r1 <= r2){
        sum += (r1-l1);
        if(l2 < l1) sum++;
        if(r1 < r2) sum++;
    }
    else{ // l1 < l2 && r2 < r1
        sum += (r2-l2+2);
    }
    cout << sum << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}