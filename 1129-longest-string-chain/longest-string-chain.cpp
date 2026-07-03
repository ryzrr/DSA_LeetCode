class Solution {
public:
    bool isPredecessor(string& word1, string& word2) {
        if (word2.size() != word1.size() + 1) return false;
        
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i] == word2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == word1.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};