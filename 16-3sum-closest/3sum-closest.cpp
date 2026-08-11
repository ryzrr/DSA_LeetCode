class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());   // Step 1: sort karo
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];   // Step 2: initial guess

        for (int i = 0; i < n - 2; i++) {   // Step 3: outer loop
            int left = i + 1;
            int right = n - 1;

            while (left < right) {          // Step 4: two-pointer
                int sum = nums[i] + nums[left] + nums[right];

                // agar ye sum, target ke zyada kareeb hai to update karo
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;      // sum badhaana hai
                } else if (sum > target) {
                    right--;     // sum ghataana hai
                } else {
                    return sum;  // exact match mil gaya, isse kareeb kuch ho hi nahi sakta
                }
            }
        }

    return closestSum;
    }

    
};