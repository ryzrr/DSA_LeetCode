class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        // If target is not found
        if (first == nums.end() || *first != target) {
            return {-1, -1};
        }

        int startIndex = first - nums.begin();
        int endIndex = last - nums.begin() - 1;

        return {startIndex, endIndex};
    }
};