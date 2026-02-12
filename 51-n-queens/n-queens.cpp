class Solution {
public:
    void solve(int row, int n, vector<string>& board, 
               vector<int>& col,
               vector<int>& leftDiag,
               vector<int>& rightDiag,
               vector<vector<string>>& ans) {
        
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            
            if (col[c] == 0 && 
                leftDiag[row + c] == 0 && 
                rightDiag[n - 1 + c - row] == 0) {
                
                board[row][c] = 'Q';
                col[c] = 1;
                leftDiag[row + c] = 1;
                rightDiag[n - 1 + c - row] = 1;
                
                solve(row + 1, n, board, col, leftDiag, rightDiag, ans);
                
                board[row][c] = '.';
                col[c] = 0;
                leftDiag[row + c] = 0;
                rightDiag[n - 1 + c - row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        vector<int> col(n, 0);
        vector<int> leftDiag(2*n - 1, 0);
        vector<int> rightDiag(2*n - 1, 0);
        
        solve(0, n, board, col, leftDiag, rightDiag, ans);
        
        return ans;
    }
};
