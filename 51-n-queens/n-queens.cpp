class Solution {
public:
    vector<vector<string>>ans;
    unordered_set<int>cols;
    unordered_set<int>diag;
    unordered_set<int>antiDiag;
    void solve(vector<string> &board,int row,int n){
        
        if(row==n){
            ans.push_back(board);
        }
        for(int col=0;col<n;col++){
            int diagConst = row+col;
            int antiDiagConst= row-col;
            if(cols.find(col)!=cols.end() ||diag.find(diagConst)!=diag.end()|| antiDiag.find(antiDiagConst)!=antiDiag.end()){
                continue;
            }
            cols.insert(col);
            diag.insert(diagConst);
            antiDiag.insert(antiDiagConst);
            board[row][col]='Q';
            solve(board,row+1,n);

            cols.erase(col);
            diag.erase(diagConst);
            antiDiag.erase(antiDiagConst);
            board[row][col]='.';



        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>  board (n,string(n,'.'));
        solve(board,0,n);
        return ans;
         
    }
};
