#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> freq, index;
    
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        if (freq[arr[i]] == 1) {
            index[arr[i]] = i;  
        }
    }

    vector<ll> unq;
    for (const auto& [num, count] : freq) {
        if (count == 1) {
            unq.push_back(index[num]);
        }
    }

    if (unq.empty()) {
        cout << 0 << endl;  
        return;
    }

    sort(unq.begin(), unq.end());

    ll max_length = 1, start = unq[0], temp_start = unq[0], length = 1;

    for (ll i = 1; i < unq.size(); i++) {
        if (unq[i] == unq[i - 1] + 1) {
            length++;
        } else {
            if (length > max_length) {
                max_length = length;
                start = temp_start;
            }
            temp_start = unq[i];
            length = 1;
        }
    }

    if (length > max_length) {
        max_length = length;
        start = temp_start;
    }

    cout << start + 1 << " " << start + max_length << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
