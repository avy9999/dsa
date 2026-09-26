class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map <string, string> mp;
        for (int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string cur = "";
        int i = 0;
        while(i < s.size()){
            if (s[i] == '('){
                i++;
                while(s[i] != ')'){
                    cur += s[i];
                    i++;
                }
                if (mp.find(cur) != mp.end()){
                    res += mp[cur];
                } else{
                    res += "?";
                }
                cur = "";
            } else{
                res += s[i];
            }
            i++;
        }
        return res;
    }
};