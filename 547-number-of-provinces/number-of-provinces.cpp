class Solution {
public:
    
    void dfs(int city, vector<vector<int>>& isConnected ,vector<bool> &visit){
        int n =  isConnected.size();
        visit[city] = true;
        for(int i = 0 ; i<n;i++){
            if(!visit[i] && isConnected[city][i] == 1){
                dfs(i,isConnected,visit);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n =  isConnected.size(); 
       vector<bool> visit(n,false);
       int province =0;
       for(int i =0 ;i<n;i++){
        if(!visit[i]){
            province++;
            dfs(i,isConnected,visit);
        }
       }

       return province ;

    }
};