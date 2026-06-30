class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {};
        int b[26] = {};
        if (s.size() != t.size()) return false;
        for (auto i : s){
            a[i-'a']++;
        }
        for (auto i : t){
            b[i-'a']++;
        }
        for (int i = 0; i < 26; i++){
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};