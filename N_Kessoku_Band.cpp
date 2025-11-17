#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define int long long
#define ull unsigned long long
using vi = vector<ll>;
using vp = vector<pair<ll, ll>>;
using pr = pair<ll, ll>;
#define pb push_back
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
class SegTree{
public:
	int len;
	vector<int> t;
	
	SegTree(){}
	SegTree(int l){
		len = l;
		t.resize(4 * len);
	}
	
	// Build Segment Tree -- build(a, 1, 0, len-1); 
	void build(vector<int>& a, int v, int tl, int tr){
		if(tl == tr){
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr)/2;
		build(a, 2*v, tl, tm);
		build(a, 2*v+1, tm+1, tr);
		t[v] = min(t[2*v], t[2*v+1]);
	}
	
	// Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
	int query(int v, int tl, int tr, int l, int r){
		if(tl > r || tr < l) return 1e9; // no overlap
		if(l <= tl && tr <= r) return t[v]; //Full overlap
		
		// Partial Overlap
		int tm = (tl + tr)/2;
		int leftAns = query(2*v, tl, tm, l, r);
		int rightAns = query(2*v+1, tm+1, tr, l, r);
		return min(leftAns, rightAns);
	}
	
	// Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, id, val) 
	void update(int v, int tl, int tr, int id, int val){
		// reached leaf node
		if(tl == id && tr == id){
			t[v] = val;
			return;
		}
		if(id > tr || id < tl) return;
		
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, id, val);
		update(2*v+1, tm+1, tr, id, val);
		t[v] = min(t[2*v], t[2*v+1]);
	}
	
	//over-ridden functions
	void build(vector<int>& a){
		build(a, 1, 0, len-1);
	}
	
	int query(int l, int r){
		return query(1, 0, len-1, l, r);
	}
	
	void update(int id, int val){
		update(1, 0, len-1, id, val);
	}
};
void solve(){
    ll n;
    cin >> n;
    vi a(n), c(n+1);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        c[a[i]] = i;
    }
    SegTree st(n);
    st.build(a);
    ll k; cin >> k;
    while(k--){
        ll l, r; cin >> l >> r;
        l--; r--;
        ll x = min(st.query(0, l-1), st.query(r+1, n-1));
        if(x >= n){
            cout << "peace" << endl; 
            continue;
        }
        cout << x << endl;
        ll i = c[x], j = c[x+1];
        c[x+1] = i; // update in the idex vector
        c[x] = j;
        st.update(i, x+1); //update in segtree
        st.update(j, x);

    }
    
}
int32_t main(){
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