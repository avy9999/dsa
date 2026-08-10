class Solution {
public:
    void generate(string curr, int o, int c, int n, vector <string>& res){
        if (curr.size() == 2*n){
            res.push_back(curr);
            return;
        }

        if (o < n) generate(curr + '(', o + 1, c, n, res);
        if (c < o) generate(curr + ')', o, c + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector <string> res;
        generate("", 0, 0, n, res);
        return res;   
    }
};