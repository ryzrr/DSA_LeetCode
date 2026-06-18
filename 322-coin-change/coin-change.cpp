class Solution {
public:
    // //memoisation
    // int solve(int ind , int target ,vector<int>& coins,vector<vector<int>>&dp ){
    //     if(ind == 0){
    //         if(target % coins[ind] == 0) return target/coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][target] != -1) return dp[ind][target];
    //     int not_pick = solve(ind-1,target,coins,dp);
    //     int pick  =1e9 ;
    //     if(target >= coins[ind]){
    //         pick = 1+ solve(ind,target-coins[ind],coins,dp);
    //     }
    //     return dp[ind][target] = min(pick,not_pick);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
        
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1)); 
    //     int ans = solve(n-1,amount,coins,dp); 
    //     if(ans >=1e9) return -1;
    //     return ans;
    // }
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,-1));
       for(int t = 0 ; t<= amount ; t++){
        if(t % coins[0] ==0 ){
            dp[0][t] = t/coins[0];
        }
        else dp[0][t] =1e9;
       }

       for(int i =1 ;  i<n ;i++){
        for(int t = 0 ; t<=amount ;t++){
            int not_pick = dp[i-1][t];
            int pick  =1e9 ;
            if(t >= coins[i]){
                pick = 1+ dp[i][t-coins[i]];
            }
            dp[i][t] = min(pick,not_pick);  
        }
       } 
       int ans = dp[n-1][amount];
       if(ans >= 1e9)  return -1;
       return ans;
    }
};