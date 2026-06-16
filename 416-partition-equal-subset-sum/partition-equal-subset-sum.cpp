class Solution {
public:
    bool solve(int ind , int target ,vector<int>& nums,vector<vector<int>> &dp ){
         int n = nums.size();
         if(target == 0) return true ;
         if(ind == 0) return (target == nums[0]);
         if(dp[ind][target] != -1 ) return dp[ind][target];
         int not_pick =  solve(ind-1 , target,nums, dp);
         int pick = 0;
         if(target >= nums[ind]){
            pick=  solve(ind-1 , target - nums[ind],nums,dp);
         }

         return  dp[ind][target] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum  =0;
        int  n = nums.size();
        int ind = n-1;
        
        for(int i =0 ; i <nums.size() ;i++){
            sum += nums[i];
        }
        if (sum % 2 != 0) return  false  ;

        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1 , -1));
        return solve(n-1,target,nums,dp);
    }
};