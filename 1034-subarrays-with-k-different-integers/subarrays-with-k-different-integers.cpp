class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int distinct = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;
            if (freq[nums[right]] == 1) {
                distinct++;
            }

            while (distinct > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    distinct--;
                }
                left++;
            }
            ans += (right - left + 1);
        }

        return ans;
    }

        int subarraysWithKDistinct(vector<int> & nums, int k) {
            return atMostK(nums,k)-atMostK(nums,k-1);
        }
    };