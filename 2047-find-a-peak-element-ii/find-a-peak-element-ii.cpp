class Solution {
public:
 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();

    int left = 0, right = n - 1;

    while (left <= right) {
        int midcolumn = (left + right) / 2;

        // Find the max row in midcolumn
        int maxRow = 0;
        for (int i = 1; i < m; ++i) {
            if (mat[i][midcolumn] > mat[maxRow][midcolumn])
                maxRow = i;
        }

        int leftVal = (midcolumn - 1 >= 0) ? mat[maxRow][midcolumn - 1] : -1;
        int rightVal = (midcolumn + 1 < n) ? mat[maxRow][midcolumn + 1] : -1;

        if (mat[maxRow][midcolumn] > leftVal && mat[maxRow][midcolumn] > rightVal) {
            return {maxRow, midcolumn};
        } else if (leftVal > mat[maxRow][midcolumn]) {
            right = midcolumn - 1;
        } else {
            left = midcolumn + 1;
        }
    }

    return {-1, -1};
    }
};