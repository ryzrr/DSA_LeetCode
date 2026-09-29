class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if (x_par == y_par)
            return;

        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;

        } else if (rank[y_par] > rank[x_par]) {
            parent[x_par] = y_par;
        } else {
            parent[y_par] = x_par;
            rank[x_par]++;
        }
    }
    int makeConnected(int V, vector<vector<int>>& connections) {
        parent.resize(V);
        rank.resize(V);
        int comp = V;
        if (connections.size() < V - 1)
            return -1;

        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (auto& c : connections) {
            if(find(c[0])!=find(c[1])) {
                Union(c[0],c[1]);
                comp--;
            }
        }

        return comp - 1;
    }
};