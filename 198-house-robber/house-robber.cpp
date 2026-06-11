class Solution {
public:
    // int solve(int n ,vector<int>& nums, vector<int>& dp){
    //         if(n==0) return nums[n];
    //         if(n<0) return 0;
    //         if(dp[n]!= -1) return dp[n];
    //         int pick =  nums[n] + solve(n-2,nums,dp);
    //         int not_pick = 0+ solve(n-1,nums,dp);
            
    //         return dp[n] = max(pick ,not_pick);
            
    // }
    int rob(vector<int>& nums) {
         int  n =nums.size();
        // vector<int>dp(n,-1);
        // return  solve(n-1,nums,dp);

        int  prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int  take = nums[i];
            if( i>1) take+= prev2;
            int not_take =  0 + prev;
            int curr  =  max(take,not_take);
            prev2 = prev; 
            prev =curr;
        }
        return prev;
    }
};