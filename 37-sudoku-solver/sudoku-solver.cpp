class Solution {
public:
    bool solve(vector<vector<char>>& b){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (b[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){
                        if (isValid(c, i, j, b)){
                            b[i][j] = c;
                            if (solve(b) == true) return true;
                            else b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(char c, int n, int m, vector<vector<char>>& b){
        for(int i = 0; i < 9; i++){
            if (b[i][m] == c) return false;
            if (b[n][i] == c) return false;
            if (b[3 * (n / 3) + i / 3][3 * (m / 3) + i % 3] == c) return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};