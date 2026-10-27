class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string row = "";
        string f = "";
        for (int i = 1; i < n; i++){
            row += "#";
            f += ".";
        }
        f += ".";
        row += ".";
        vector <string> res;
        res.push_back(f);
        for (int i = 0; i < m - 1; i++){
            res.push_back(row);
        }
        return res;
    }
};