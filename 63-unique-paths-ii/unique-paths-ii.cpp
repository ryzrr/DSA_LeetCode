class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Agar shuruat mein hi obstacle hai
        if (obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Starting point
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Agar obstacle mila, toh wahan raste 0 honge
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    // Upar se aaye + Left se aaye
                    if (i > 0) dp[i][j] += dp[i-1][j];
                    if (j > 0) dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};