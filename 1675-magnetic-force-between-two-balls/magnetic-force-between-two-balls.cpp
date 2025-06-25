class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int m, int minDist) {
        int count = 1;  // place first ball at the first position
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 1;
        int high = position.back() - position[0];
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canPlaceBalls(position, m, mid)) {
                ans = mid;
                low = mid + 1;  // try to increase the distance
            } else {
                high = mid - 1; // need to reduce the distance
            }
        }

        return ans;
    }
};