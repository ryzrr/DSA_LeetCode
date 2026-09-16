class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            //  both side undirected  so we  reverse  the  direction also 
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0] =1;
        dist[0] =0 ;
        int mod = (int)1e9+7;

        //min heap to   do  the  dijkstra  and  mind the shprtest  paths
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
        // dist, node  ke  form  mein store  hai 
        pq.push({0,0});
        while(!pq.empty()){
        long long dis  =  pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it.first;
            long long edW =  it.second;
            if(edW + dis < dist[adjNode]){
                dist[adjNode] = edW + dis;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode],adjNode});
            }
            else if(edW +  dis ==  dist[adjNode]){
                ways[adjNode] =  (ways[node] + ways[adjNode])%mod;
            }
        }
        }
        return ways[n-1] %mod;
    }
};