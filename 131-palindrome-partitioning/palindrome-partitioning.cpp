class Solution {
public:
    bool palindrome(string s, int l, int r){
        while(l <= r){
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void checkPartition(int index, string s, vector <string>& ans, vector <vector <string>>& res){
        if (index == s.size()){
            res.push_back(ans);
            return;
        }
        for (int i = index; i < s.size(); ++i){
            if (palindrome(s, index, i)){
                ans.push_back(s.substr(index, i - index + 1));
                checkPartition(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector <vector <string>> res;
        vector <string> ans;
        checkPartition(0, s, ans, res);
        return res;
    }
};