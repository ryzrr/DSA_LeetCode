class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool isZero  =  false;
        int  total  =0;
        for(int x: nums){
            total ^= x;
            if(x!=0) isZero = true;
        }

        if(total!=0) return n;
        if(isZero) return n-1;
        return 0;
    }
};