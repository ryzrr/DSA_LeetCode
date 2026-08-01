class Solution {
public:
    void dfs(int row , int col ,  int oldColor , vector<vector<int>>& image,int color ){
        int n = image.size();
        int m = image[0].size();
        image[row][col] = color;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i =0; i<4;i++){
            int nrow =  row + dr[i];
            int ncol =  col + dc[i];
            if(nrow>=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == oldColor){
                dfs(nrow,ncol,oldColor,image,color);
            }
        }
    } 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int oldColor =  image[sr][sc];
       if(oldColor == color ){
             return image ;
       }
       dfs(sr,sc,oldColor,image,color);
       return image;
    }
};