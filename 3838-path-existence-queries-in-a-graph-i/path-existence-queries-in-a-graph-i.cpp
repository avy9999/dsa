class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector <int> dir(n);
        dir[0] = 0;
        for (int i = 1; i < n; i++){
            if (abs(nums[i] - nums[i-1]) <= maxDiff){
                dir[i] = 0 + dir[i-1];
            } else{
                dir[i] = -1 + dir[i-1];
            }
        }
        vector <bool> ans;
        for (auto i : queries){
            if (i[0] == i[1]){
                ans.push_back(true);
            } else{
                if ((dir[i[1]] - dir[i[0]]) == 0){
                    ans.push_back(true);
                } else{
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};