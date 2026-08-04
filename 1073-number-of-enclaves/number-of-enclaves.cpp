class Solution {
public:
    void dfs(int row, int col ,  vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 or row >= n or col < 0 or col >= m or grid[row][col] != 1){
                return;
        }
        
        grid[row][col] = 0 ;   // safe  cells  hai  yeh  
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int i =0 ;i<4 ;i++){
            int nrow = row +dr[i];
            int mcol = col + dc[i];
            dfs(nrow,mcol,grid);
            
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

        for(int i = 0 ; i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid);
            }
            if(grid[n-1][i] == 1){
                dfs(n-1,i,grid);
            }
        }
        for(int i = 0 ; i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][m-1] == 1){
                dfs(i,m-1,grid);
            }
        }
        int cnt =0;
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};