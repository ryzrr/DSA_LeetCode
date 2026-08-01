class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh =0;
        for(int i =0 ; i<n ;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 2 ){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                        fresh++;
                }
            }
        }
        int t = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty() && fresh > 0 ){
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int,int> curr = q.front();
                q.pop();
                int row = curr.first;
                int col = curr.second;
                
                for (int d = 0; d < 4; d++) {
                    int newRow = row + dr[d];
                    int newCol = col + dc[d];
                    
                    if (newRow >= 0 && newRow < n && 
                        newCol >= 0 && newCol < m &&
                        grid[newRow][newCol] == 1) {
                        
                        grid[newRow][newCol] = 2;   
                        fresh--;
                        q.push({newRow, newCol});
                    }
                }
            }
            t++;

        }
        if(fresh>0) return -1;
        else  return t;
    }
};