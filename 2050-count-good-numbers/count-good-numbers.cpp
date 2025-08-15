class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modpow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;       
        
        long long ans = (modpow(5, even_count) * modpow(4, odd_count)) % MOD;
        return (int)ans;
    }
};
