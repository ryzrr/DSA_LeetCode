class Solution {
public:
    int trap(vector<int>& height) {
      
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Step 1: Har index ke liye Left ki sabse unchi deewar nikalo
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Step 2: Har index ke liye Right ki sabse unchi deewar nikalo
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Step 3: Pani calculate karo
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // Pani = min(Left deewar, Right deewar) - Zameen(height)
            int waterLevel = min(leftMax[i], rightMax[i]);
            ans += waterLevel - height[i];
        }

        return ans;
    }
};