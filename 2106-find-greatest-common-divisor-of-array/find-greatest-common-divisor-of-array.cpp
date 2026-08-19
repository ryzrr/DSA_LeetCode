class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  first =  nums[0];
        int last   = nums[nums.size()-1];
        while (first != 0) {
            int temp = last % first;
            last = first;
            first = temp;
        }
        return last;
    }
};