class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char mn = s[0];
        char mx = s[0];
        if (is_sorted(begin(s), end(s))) return 0;
        if (n == 2){
            return -1;
        }
        for (auto i : s){
            mn = min(mn, i);
            mx = max(mx, i);
        }
        if (mn == s[0] || mx == s[n - 1]) return 1;
        for (int i = 1; i < n - 1; i++){
            if (mn == s[i] || mx == s[i]){
                return 2;
            }
        }
        return 3;
    }
};