class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector <vector <int>> t;
        for (auto &v : intervals){
            t.push_back({v[0], 1});
            t.push_back({v[1] + 1, -1});
        }
        int ans = 0, cur = 0;
        sort(t.begin(), t.end());
        for (auto &v : t){
            cur += v[1];
            ans = max(ans, cur);
        }
        return ans;
    }
};