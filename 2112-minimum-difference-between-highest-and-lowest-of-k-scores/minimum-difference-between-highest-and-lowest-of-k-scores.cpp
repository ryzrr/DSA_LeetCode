class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;
        int l=0;
        while(k+l-1<nums.size()) {
            ans = min(ans, nums[k+l-1] - nums[l]);
            
            l++;
        }

        return ans;
    
}
}
;