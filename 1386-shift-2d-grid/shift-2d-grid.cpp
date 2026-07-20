class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m == 1 && n == 1) || (k % (m*n) == 0)) return grid;
        vector <int> v (m*n, 0);
        int index = k % (m * n);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                v[index] = grid[i][j];
                index++;
                if (index >= m*n) index = 0;
            }
        }
        index = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                grid[i][j] = v[index++];
            }
        }
        return grid;
    }
};