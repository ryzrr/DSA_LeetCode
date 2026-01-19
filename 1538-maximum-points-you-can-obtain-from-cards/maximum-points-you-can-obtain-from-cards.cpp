class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        int windowSize = n - k;

        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minsum = windowSum;
        for (int i = windowSize; i < n; i++) {
            windowSum = windowSum + cardPoints[i] - cardPoints[i - windowSize];
            if (windowSum < minsum) {
                minsum = windowSum;
            }
        }

        return total - minsum;
    }
};
