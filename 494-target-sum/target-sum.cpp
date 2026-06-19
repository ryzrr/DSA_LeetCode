class Solution {
public:
    int f(int target , int ind  ,vector<int>& arr,vector<vector<int>> &dp ){
        if(ind == 0){
            if(target == 0  &&  arr[ind] == 0) return 2;
            if(target == 0 || target == arr[ind]) return 1;
            else return 0 ;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int pick =  0;
        if(target >= arr[ind]){
            pick = f(target - arr[ind] , ind -1,arr,dp);
        }
        int not_pick  = f(target , ind - 1,arr,dp);
        return dp[ind][target] =pick + not_pick;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n= arr.size();
        int total = 0;
        for(auto it : arr){
            total+= it ;
        }
        int target = (total + diff)/2;
        if((total+diff)%2 != 0 || total <diff) return 0;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(target,n-1,arr,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        return countPartitions(nums,target);
    }
};