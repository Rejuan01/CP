#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
using ll = long long;
using ull = unsigned long long;
using vd = vector<double>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
pr check(vd &a, double m, ll d){ // check if mean can be >= m in any segment of len >= d; Returns the segment [l, r]
    ll n = a.size()-1;
    vd pref(n+1);
    vector<pair<double, ll>> minPref(n+1);
    for(ll i = 1; i <= n; i++){
        pref[i] = a[i]-m;               // substract m
        pref[i] += pref[i-1];           // prefix sum
        minPref[i].first = pref[i];
        minPref[i].second = i;
        if(minPref[i].first > minPref[i-1].first){   // min prefix till now and its idx updated
            minPref[i].first = minPref[i-1].first;
            minPref[i].second = minPref[i-1].second;
        }
    }
    for(ll i = d; i <= n; i++){
        if(pref[i]-minPref[i-d].first >= 0){   // if the max subarray sum ends at i can be >= 0
            ll j = minPref[i-d].second+1;
            return {j, i};
        }
    }
    return {1, -1};    // any invalid range returned
}
void solve(){
    ll n, d;
    cin >> n >> d;
    vd a(n+1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    double l = 0, r = 101;
    while(l+1e-6 < r){              // find the max mean value that satisfies the condition
        double m = (l+r)/2;
        auto p = check(a, m, d);
        if(p.first <= p.second) l = m;
        else r = m;
    }
    auto p = check(a, l, d);
    cout << p.first << " " << p.second << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
       solve();
    }
    return 0;
}