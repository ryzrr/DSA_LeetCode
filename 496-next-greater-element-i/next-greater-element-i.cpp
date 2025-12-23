class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        int n = num2.size();
        vector<int> nge(n);
        stack<int> st;
        unordered_map<int, int> mpp; 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= num2[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? -1 : st.top();
            st.push(num2[i]);

            mpp[num2[i]] = nge[i]; 
        }

      
        vector<int> ans;
        for (int i = 0; i < num1.size(); i++) {
            ans.push_back(mpp[num1[i]]);
        }

        return ans;
    }
};
