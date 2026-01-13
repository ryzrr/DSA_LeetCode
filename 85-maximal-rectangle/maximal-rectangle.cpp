class Solution {
public:
     vector<int>nextSmallerElement(vector<int>&heights){
        int n=heights.size();
        vector<int>NSE(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
        while(!st.empty()&& heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            NSE[i]=n;
        }
        else{
                NSE[i]=st.top();
            }
            st.push(i);
        }
        return NSE;

    }
    vector<int>prevSmallerElement(vector<int>& heights){
         int n=heights.size();
        vector<int>PSE(n);
        stack<int> st;
        for(int i=0;i<n;i++){
        while(!st.empty()&& heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(st.empty()){
            PSE[i]=-1;
        }
        else{
                PSE[i]=st.top();
            }
            st.push(i);
        }
        return PSE;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSE = nextSmallerElement(heights);
         vector<int> PSE = prevSmallerElement(heights);
         int area = heights[0];
        for(int i=0; i < heights.size();i++){        
         int width = NSE[i]-PSE[i]-1;
         area = max(area,heights[i]*width);
        }
        return area ;

    }



    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int col = matrix[0].size();

        vector<int> heights(col, 0);
        int maxarea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < col; c++) {
                if (matrix[r][c] == '1')
                    heights[c] += 1;
                else
                    heights[c] = 0;
            }

            maxarea = max(maxarea, largestRectangleArea(heights));
        }
        return maxarea; 
    }
};