class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int mn = INT_MAX;
        bool allEven = true;
        
        for (int num : nums1) {
            mn = min(mn, num);
            if (num % 2 != 0) {
                allEven = false;
            }
        }
        
        // Agar minimum number odd hai -> hamesha possible
        if (mn % 2 == 1) {
            return true;
        }
        
        // Agar minimum even hai -> tabhi possible jab sab even hon
        return allEven;
    }
};