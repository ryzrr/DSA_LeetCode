class Solution {
public:
    string reverseWords(string s) {
       
        vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // Capture word
            int j = i;
            while (j < n && s[j] != ' ') j++;

            words.push_back(s.substr(i, j - i));
            i = j;
        }

        reverse(words.begin(), words.end());

        string result;
        for (int k = 0; k < words.size(); ++k) {
            result += words[k];
            if (k < words.size() - 1) result += " ";
        }

        return result;
    }
        
   
};