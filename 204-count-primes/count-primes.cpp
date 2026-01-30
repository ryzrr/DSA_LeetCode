class Solution {
public:
    int countPrimes(int n) {
     if (n <= 2) return 0;

        vector<bool> checkPrime(n, true);
        checkPrime[0] = false;
        checkPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (checkPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    checkPrime[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (checkPrime[i]) cnt++;
        }

        return cnt;   
    }
};