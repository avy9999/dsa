class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int idx){
        if (idx == word.size()){
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        char cur = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(i + 1, j, board, word, idx + 1) || dfs(i, j + 1, board, word, idx + 1) || dfs(i - 1, j, board, word, idx + 1) || dfs(i, j - 1, board, word, idx + 1);

        board[i][j] = cur;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (dfs(i, j, board, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};