class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1] == 1 || grid[0][0] == 1)  return -1;


        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0] = true;

        int dist = 1;
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int  lvl =  q.size();
            for(int i  =0 ;i <lvl;i++){
                pair<int,int> node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                if (row == n-1 && col == n-1) {
                return dist;
                }

                
                for(int d =0 ;d < 8;d++){
                    int  nrow  =  row +dx[d];
                    int  mcol  = col +dy[d];

                    if(nrow >=0 &&  nrow < n && mcol >=0  && mcol <n && grid[nrow][mcol] == 0 && !visited[nrow][mcol] ){
                            q.push({nrow,mcol});
                            visited[nrow][mcol] = true;

                    }
                }
            }
            dist++ ;
        }
        return -1;
    }
};