class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> result(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j=0; j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0}; 
        int dist  =0 ;
        while(!q.empty()){
            int size = q.size();
            dist++;
            for(int i = 0; i<size;i++){
                pair<int,int> node = q.front();
                int row =  node.first ; 
                int col =  node.second;
                q.pop();
                for(int i =0 ; i<4;i++){
                    int nrow = row +dr[i];
                    int mcol = col +dc[i];
                    if(nrow >=0 && nrow < n && mcol >=0 && mcol < m && !visited[nrow][mcol]){
                        result[nrow][mcol] = dist;
                        q.push({nrow,mcol});
                        visited[nrow][mcol] = true;
                    }
                }
            }
        }
        return result;
    }
};