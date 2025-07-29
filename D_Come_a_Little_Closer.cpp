#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
void solve(){
    ll n;
    cin >> n;
    vi X, Y;
    set<pr> s;
    map<ll, ll> mx, my;
    for(ll i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        s.insert({x, y});
        X.push_back(x); Y.push_back(y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll x1 = X[0], x2 = X[n-1];
    ll y1 = Y[0], y2 = Y[n-1];
    ll d1 = x2-x1+1;
    ll d2 = y2-y1+1;
    ll dx = d1, dy = d2;
    ll A = d1*d2;
    bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    if(n > 1 && X[1] != x1){
        ll x = X[1];
        ll d = x2-x+1;
        ll A1 = d*d2;
        if(d*d2 == n-1) A1 += min(d, d2);
        if(A1 < A){
            A = A1;
            dx = d;
        }
        f1 = 1;
    }
    if(n > 1 && X[n-2] != x2){
        ll x = X[n-2];
        ll d = x-x1+1;
        ll A1 = d*d2;
        if(d*d2 == n-1) A1 += min(d, d2);
        if(A1 < A){
            A = A1;
            dx = d;
        }
        f2 = 1;
    }
    if(n > 1 && Y[1] != y1){
        ll y = Y[1];
        ll d = y2-y+1;
        ll A1 = d1*d;
        if(d1*d == n-1) A1 += min(d1, d);
        if(A1 < A){
            A = A1;
            dx = d1;
            dy = d;
        }
        f3 = 1;
    }
    if(n > 1 && Y[n-2] != y2){
        ll y = Y[n-2];
        ll d = y-y1+1;
        ll A1 = d1*d;
        if(d1*d == n-1) A1 += min(d1, d);
        if(A1 < A){
            A = A1;
            dx = d1;
            dy = d;
        }
        f4 = 1;
    }
    if(s.find({x1, y1}) != s.end() && f1 && f3){
        ll x = X[1], y = Y[1];
        ll A1 = (x2-x+1)*(y2-y+1);
        if((x2-x+1)*(y2-y+1) == n-1) A1 += min((x2-x+1),(y2-y+1));
        if(A1 < A){
            A = A1;
            dx = x2-x+1;
            dy = y2-y+1;
        }
    }
    if(s.find({x1, y2}) != s.end() && f1 && f4){
        ll x = X[1], y = Y[n-2];
        ll A1 = (x2-x+1)*(y-y1+1);
        if((x2-x+1)*(y-y1+1) == n-1) A1 += min((x2-x+1),(y-y1+1));
        if(A1 < A){
            A = A1;
            dx = x2-x+1;
            dy = y-y2+1;
        }
    }
    if(s.find({x2, y1}) != s.end() && f2 && f3){
        ll x = X[n-2], y = Y[1];
        ll A1 = (x-x1+1)*(y2-y+1);
        if((x-x1+1)*(y2-y+1) == n-1) A1 += min((x-x1+1),(y2-y+1));
        if(A1 < A){
            A = A1;
            dx = x-x1+1;
            dy = y2-y+1;
        }
    }
    if(s.find({x2, y2}) != s.end() && f2 && f4){
        ll x = X[n-2], y = Y[n-2];
        ll A1 = (x-x1+1)*(y-y1+1);
        if((x-x1+1)*(y-y1+1) == n-1) A1 += min((x-x1+1),(y-y1+1));
        if(A1 < A){
            A = A1;
            dx = x-x1+1;
            dy = y-y1+1;
        }
    }
    cout << A << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}