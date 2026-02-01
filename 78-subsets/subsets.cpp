class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //      int n = nums.size();
    //     int total = 1 << n;

    //     vector<vector<int>> ans;

    //     for (int mask = 0; mask < total; mask++) {
    //         vector<int> subset;

    //         for (int i = 0; i < n; i++) {
    //             if (mask & (1 << i)) {
    //                 subset.push_back(nums[i]);
    //             }
    //         }

    //         ans.push_back(subset);
    //     }

    //     return ans;
    // }
vector<vector<int>> ans;
    void solve(int index, vector<int>& nums, vector<int>& curr) {

        if (index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        solve(index + 1, nums, curr);
        curr.pop_back();

        solve(index + 1, nums, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solve(0, nums, curr);
        return ans;
    }
};