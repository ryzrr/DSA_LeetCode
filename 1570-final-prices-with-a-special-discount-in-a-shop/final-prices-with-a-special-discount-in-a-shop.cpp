class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
      int n = prices.size();
      stack<int>st;
      vector<int>ngs(n,0);
      vector<int>ans(n,0);

      for(int i=0;i<n;i++){
        while(!st.empty()&&prices[st.top()] >=prices[i]){
            ngs[st.top()] = prices[i];
            st.pop();
        }
        st.push(i);
      }

      for(int i=0;i<n;i++){
            ans[i] = prices[i]-ngs[i];
      }

      return  ans;
    }
};