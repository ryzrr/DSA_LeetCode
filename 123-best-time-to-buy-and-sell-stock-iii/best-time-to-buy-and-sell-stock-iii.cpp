class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //  3  staes  vary  kr rha  hai  ind buy  and max  capacity that is  2  here s  3d dp 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind = n-1 ; ind>=0 ;ind--){
            for(int buy= 0 ; buy <=1 ; buy ++){
                for(int cap =1; cap<=2;cap++){
                    if(buy==1){
                        int pick = -prices[ind] + dp[ind+1][0][cap];
                        int not_pick = 0 + dp[ind+1][1][cap];
                        dp[ind][buy][cap] = max(pick , not_pick);
                    }
                    else{
                        int pick =  prices[ind] +  dp[ind+1][1][cap-1];
                        int not_pick =  0 + dp[ind+1][0][cap];
                        dp[ind][buy][cap] = max(pick , not_pick);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};