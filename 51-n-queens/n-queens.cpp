class Solution {
public:
    bool safe(int row, int col, vector <string>& board, int n){
        int drow = row;
        int dcol = col;

        while(row >= 0 && col >= 0){
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        col = dcol;
        row = drow;
        while(col >= 0){
            if (board[row][col] == 'Q') return false;
            col--;
        }

        col = dcol;
        row = drow;
        while(row < n && col >= 0){
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector <string>& board, vector <vector <string>>& res, int n){
        if (col == n){
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++){
            if (safe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, res, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> res;
        vector <string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; ++i){
            board[i] = s;
        }
        solve(0, board, res, n);
        return res;
    }
};