class Solution {
public:
 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
    int n = mat[0].size();

    int left = 0, right = n - 1;

    while (left <= right) {
        int midCol = (left + right) / 2;

        // Find the max row in midCol
        int maxRow = 0;
        for (int i = 1; i < m; ++i) {
            if (mat[i][midCol] > mat[maxRow][midCol])
                maxRow = i;
        }

        int leftVal = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
        int rightVal = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

        if (mat[maxRow][midCol] > leftVal && mat[maxRow][midCol] > rightVal) {
            return {maxRow, midCol};
        } else if (leftVal > mat[maxRow][midCol]) {
            right = midCol - 1;
        } else {
            left = midCol + 1;
        }
    }

    return {-1, -1};
    }
};