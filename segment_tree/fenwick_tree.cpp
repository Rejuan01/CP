// ---------------- Fenwick Tree (Binary Indexed Tree) ----------------
// Supports prefix sums and point updates in O(log n)
// Use 1-based indexing for simplicity

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    // Add value `val` at index `i`
    void add(int i, long long val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    // Sum of range [1..i]
    long long sum(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // Range sum [l..r]
    long long sum(int l, int r) const {
        return sum(r) - sum(l - 1);
    }

    // Get single value at index i (if you only do add() and sum())
    long long get(int i) const {
        return sum(i) - sum(i - 1);
    }
};
