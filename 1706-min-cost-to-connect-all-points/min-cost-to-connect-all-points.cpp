class Solution {
public:

    int primAlgo(int V, vector<vector<pair<int,int>>>& adj) {
        // code here
        int  sum  = 0;
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<bool> inMST(V,false);
        while(!pq.empty()){
            
            auto it  =  pq.top();
            pq.pop();
            
            int node =  it.second;
            int wt = it.first;
            
            if(inMST[node] == true)  continue;
            inMST[node] =true;
            sum+=wt;
            
            for(auto &p : adj[node]){
                
                auto ng =  p.first;
                auto  ngwt = p.second;
                
                if(inMST[ng]==false){
                    pq.push({ngwt,ng});
                    
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
      int V = points.size();
      vector<vector<pair<int,int>>> adj(V);
      for(int i = 0; i<V;i++){
         for(int j = i+1; j <V;j++){
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1 = points[i][1];
            int y2 = points[j][1];

            int d =  abs(x1 -x2) + abs(y1 -y2);
            adj[i].push_back({j,d});
            adj[j].push_back({i,d});

         }

      }    


      return primAlgo(V,adj);
    }
};