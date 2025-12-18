// ======= MODULAR TOOLKIT (REUSABLE) =======

const long long MOD = 1e9+7;   // must be prime for Fermat inverse

// Fast power: a^b % mod
long long modpow(long long a, long long b, long long mod = MOD) {
    long long r = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

// Fermat little theorem: inverse of a mod p (p prime)
long long modinv(long long a, long long mod = MOD) {
    return modpow(a, mod - 2, mod);     // a^(p-2) % p
}

// Precompute factorials for nCr / nPr
vector<long long> fact, invfact;

void init_fact(int n, long long mod = MOD) {
    fact.assign(n+1, 0);
    invfact.assign(n+1, 0);

    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i) % mod;

    invfact[n] = modinv(fact[n], mod);
    for(int i = n - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}

// nCr = n! / (r! * (n-r)!)
long long nCr(int n, int r, long long mod = MOD) {
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % mod) * invfact[n-r]) % mod;
}

// nPr = n! / (n-r)!
long long nPr(int n, int r, long long mod = MOD) {
    if(r < 0 || r > n) return 0;
    return (fact[n] * invfact[n-r]) % mod;
}
