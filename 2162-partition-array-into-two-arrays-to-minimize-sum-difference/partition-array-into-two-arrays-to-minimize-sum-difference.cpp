class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        
        // 2D arrays banayenge jisme index ka matlab hai "kitne elements pick kiye"
        // left[size] mein wo saare sum honge jo exactly 'size' elements ko jod kar bane hain
        vector<vector<int>> left(n + 1), right(n + 1);
        
        // Step 1 & 2: Generate all subsets using Bitmasking
        // (1 << n) ka matlab hai 2^n. Hum 0 se 2^n - 1 tak loops chala rahe hain
        for (int mask = 0; mask < (1 << n); mask++) {
            int size = 0, l_sum = 0, r_sum = 0;
            
            // Check karte hain ki mask mein kaunsi bits '1' hain (Pick)
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) { 
                    size++;
                    l_sum += nums[i];           // Left half ka sum
                    r_sum += nums[i + n];       // Right half ka sum
                }
            }
            left[size].push_back(l_sum);
            right[size].push_back(r_sum);
        }
        
        // Step 3: Right half ke arrays ko sort karo taaki Binary Search lag sake
        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }
        
        // Shuruat mein minimum difference maan lete hain ki ya toh saare left se liye honge
        // Ya phir saare exactly right half se liye honge
        int min_diff = min(abs(totalSum - 2 * left[n][0]), abs(totalSum - 2 * right[n][0]));
        
        // Step 4: The "Meet in the Middle" Logic
        // Agar main left se 'sz' elements leta hoon, toh rule ke hisaab se mujhe 
        // right se bache hue 'n - sz' elements lene hi padenge.
        for (int sz = 1; sz < n; sz++) {
            for (int a : left[sz]) {
                
                // Humara target kya hai? Hum chahte hain: a + b = totalSum / 2
                // Jisse 'b' aayega: b = (totalSum - 2 * a) / 2
                int b_target = (totalSum - 2 * a) / 2; 
                
                int right_sz = n - sz;
                auto& v = right[right_sz];
                
                // Binary Search: Target ke sabse kareebi value dhoondo
                auto it = lower_bound(v.begin(), v.end(), b_target);
                
                // Case 1: Target ke aage ya barabar wali value mili
                if (it != v.end()) {
                    min_diff = min(min_diff, abs(totalSum - 2 * (a + *it)));
                }
                
                // Case 2: Target ke theek peechhe wali value (kyunki exact match zaroori nahi)
                if (it != v.begin()) {
                    auto it2 = it;
                    it2--; // Ek step peeche gaye
                    min_diff = min(min_diff, abs(totalSum - 2 * (a + *it2)));
                }
            }
        }
        
        return min_diff;
    }
};