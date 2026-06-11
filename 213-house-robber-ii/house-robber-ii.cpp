class Solution {
public:
    // Yeh tumhara wala logic hai, bilkul sahi
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) take += prev2;
            int not_take =0+ prev;
            
            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());
        return max(robLinear(first), robLinear(second));
    }
};