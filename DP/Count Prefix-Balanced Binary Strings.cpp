class Solution {
private:
    static const long long MOD = 1000000007LL;

    // Helper method to compute power modulo MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    // Helper method to compute modular inverse
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int prefixStrings(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        long long catalan = 1;

        // Compute C_i from C_{i-1}
        for (int i = 1; i <= n; i++) {
            long long numerator = (4LL * i - 2) % MOD;
            long long denominatorInverse = modInverse(i + 1);

            // C_i = C_{i-1} * (4i - 2) * inv(i + 1)
            catalan = (catalan * numerator) % MOD;
            catalan = (catalan * denominatorInverse) % MOD;
        }

        return (int)catalan;
    }
};
