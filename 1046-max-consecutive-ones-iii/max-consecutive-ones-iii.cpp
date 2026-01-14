class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int zero =0;int n=nums.size();int ans=0;
        while(r<n){
            if(nums[r]==0)zero++;
            while(l<n&&zero>k){
                if(nums[l]==0)zero--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};