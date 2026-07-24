class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        int p[3] = {-1, -1, -1};
        for (int i = 0; i < n; i++){
            p[(s[i] & 31) - 1] = i;
            cnt += min({p[0], p[1], p[2]}) + 1;
        }
        return cnt;
    }
};