class Solution {
public:
bool canEatAll(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;  // ceil(bananas / k)
        }
        return hours <= h;
    }

int minEatingSpeed(vector<int>& piles, int h) {
        
    int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(piles, h, mid)) {
                ans = mid;         // possible answer, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;     // too slow, try faster
            }
        }
        return ans;
}
        
    
};