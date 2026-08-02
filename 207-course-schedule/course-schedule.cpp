class Solution {
public:
  
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        for(auto &p : prerequisites){
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses ;i++){
            if(indeg[i]==0) q.push(i);
        }
        int  done =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            done++;
            for( auto nxt : adj[node]){
                indeg[nxt]--;
                if(indeg[nxt] == 0) q.push(nxt);
                // indeg[nxt]--;
            }
        }
        return done== numCourses;
    }
};