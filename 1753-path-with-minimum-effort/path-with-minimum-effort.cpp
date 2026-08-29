class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        // min-heap: {effort, row, col}
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [effort, x, y] = pq.top();
            pq.pop();

            if (x == m-1 && y == n-1) return effort;
            if (effort > dist[x][y]) continue; // stale entry

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;
                    pq.push({newEffort, nx, ny});
                }
            }
        }
        return 0;
    }
};