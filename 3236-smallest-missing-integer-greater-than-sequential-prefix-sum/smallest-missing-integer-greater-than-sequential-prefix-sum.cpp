class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]+1;
        int id  =0;
        int sums =nums[0];
        for(int i  =1;i<nums.size();i++){
            if(nums[i] != nums[i-1]+1){
                id = i-1;
                break;
            }
            sums += nums[i];
        }
        sort(nums.begin(),nums.end());
        for(auto it : nums){
            if(sums == it){
                sums++;
            }
        }
        return sums;
        
    }
};