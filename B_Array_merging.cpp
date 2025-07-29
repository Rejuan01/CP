#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        map<int, int> mpA;
        map<int, int> mpB;
        for(int i = 0; i < n; i++){
            int c = 1;
            for(; i < n-1 && a[i] == a[i+1]; i++){
                c++;
            }
            if(mpA[a[i]] < c){
                mpA[a[i]] = c;
            }
        }
        for(int i = 0; i < n; i++){
            int c = 1;
            for(; i < n-1 && b[i] == b[i+1]; i++){
                c++;
            }
            if(mpB[b[i]] < c){
                mpB[b[i]] = c;
            }
        }
        int ans = 0;
        for(const auto &[v, f] : mpA){
            if(f+mpB[v] > ans) ans = f+mpB[v];
        }
        for(const auto &[v, f] : mpB){
            if(f+mpA[v] > ans) ans = f+mpA[v];
        }
        cout << ans << endl;
    }
}