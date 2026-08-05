class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>& grid,vector<vector<bool>>& visit){
        int n =  grid.size();
        int m =  grid[0].size();
        if(row < 0 or row >=n or col < 0 or col >=m or visit[row][col] == true or grid[row][col] == '0') {
            return;
        }
        visit[row][col] = true;
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int d = 0 ; d < 4;d++){
            int nrow = row +dr[d];
            int mcol = col + dc[d];
            dfs(nrow,mcol,grid,visit);
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n =  grid.size();
        int m =  grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        int cnt =0 ;
        for(int i = 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == '1' and !visit[i][j]){
                    cnt++;
                    dfs(i,j,grid,visit);
                }
            }
        }
        return cnt;
        
    }
};