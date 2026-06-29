class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, char> sp;
        unordered_map <char, char> tp;
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (sp.find(s[i]) != sp.end() || tp.find(t[i]) != tp.end()){
                if (sp[s[i]] != t[i] || tp[t[i]] != s[i]){
                    return false;
                }
            } else{
                sp[s[i]] = t[i];
                tp[t[i]] = s[i];
            }
        }
        return true;
    }
};