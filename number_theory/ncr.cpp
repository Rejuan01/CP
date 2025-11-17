const int MOD = 1e9 + 7;
const int MAXN = 2000000;   // adjust as needed

long long fact[MAXN+1], invfact[MAXN+1];

long long binpow(long long a, long long b) {
    long long r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN] = binpow(fact[MAXN], MOD - 2); // Fermat inverse
    for (int i = MAXN; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

// use
int main() {
    init(); // only once

    cout << nCr(14, 4) << "\n"; // example
}
