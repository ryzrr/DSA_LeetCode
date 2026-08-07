class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
		for (auto &it : edges) {
			adj[it[1]].push_back(it[0]);
		}
		
		queue<int> q;
		vector<int> indegree(V, 0);
		for (int i = 0; i<V; i++) {
			for (auto &it : adj[i]) {
				indegree[it] ++;
				
			}
		}
		for (int i = 0; i<V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		
		vector<int> ans;
        int cnt = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
            cnt++;
			ans.push_back(node);;
			for (auto &it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) {
					q.push(it);
				}
			}
		}
		if (cnt == V)return ans;
		else return {};  
    }
};