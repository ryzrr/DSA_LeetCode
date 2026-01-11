class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If k still remains, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result string
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < result.size() && result[idx] == '0') {
            idx++;
        }
        result = result.substr(idx);

        return result.empty() ? "0" : result;
    }
};
