class Solution {
public:
    vector<vector<int>> memo;
    vector<int> balloons;
    
    int solve(int left, int right) {
        // base case: agar beech mein koi balloon nahi hai
        if (left + 1 == right) {
            return 0;
        }
        
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        
        int maxCoins = 0;
        
        // "last balloon jo phodenge" - k try karo left+1 se right-1 tak
        for (int k = left + 1; k < right; k++) {
            int coins = balloons[left] * balloons[k] * balloons[right]
                        + solve(left, k) + solve(k, right);
            maxCoins = max(maxCoins, coins);
        }
        
        memo[left][right] = maxCoins;
        return maxCoins;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // boundary balloons add karo (virtual 1's)
        balloons.push_back(1);
        for (int num : nums) balloons.push_back(num);
        balloons.push_back(1);
        
        int m = balloons.size();
        memo.assign(m, vector<int>(m, -1));
        
        return solve(0, m - 1);
    }
};