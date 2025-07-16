class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            multiset<int> ms;
            
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                
                // If current char had a frequency > 0, update in multiset
                if (freq[idx] > 0) {
                    ms.erase(ms.find(freq[idx]));  // Remove old frequency
                }
                
                freq[idx]++;                      // Increase frequency
                ms.insert(freq[idx]);             // Insert new frequency
                
                int minFreq = *ms.begin();
                int maxFreq = *ms.rbegin();
                totalBeauty += (maxFreq - minFreq);
            }
        }
        
        return totalBeauty;
    }
};
