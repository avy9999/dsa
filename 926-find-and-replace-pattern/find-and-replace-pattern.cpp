class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector <string> res;
        unordered_map <char, char> mp;
        string p = "";
        for (int i = 0; i < n; i++){
            if (mp[pattern[i]]){
                p += mp[pattern[i]];
            } else{
                mp[pattern[i]] = i + '0';
                p += i;
            }
        }

        for (auto word : words){
            unordered_map <char, char> ch;
            string c = "";
            for (int i = 0; i < n; i++){
                if (ch[word[i]]){
                    c += ch[word[i]];
                } else{
                    ch[word[i]] = i + '0';
                    c += i;
                }
            }
            if (c == p) res.push_back(word);
        }
        cout << p;
        return res;
    }
};