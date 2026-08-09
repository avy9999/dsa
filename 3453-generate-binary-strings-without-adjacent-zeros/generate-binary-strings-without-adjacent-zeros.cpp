class Solution {
public:
    void generate(int n, string curr, vector <string> &res){
        if (curr.size() == n){
            res.push_back(curr);
            return;
        }

        generate(n, curr + '1', res);

        if (curr.empty() || curr.back() != '0'){
            generate(n, curr + '0', res);
        }
    }
    vector<string> validStrings(int n) {
        vector <string> res;
        generate(n, "", res);
        return res;
    }
};