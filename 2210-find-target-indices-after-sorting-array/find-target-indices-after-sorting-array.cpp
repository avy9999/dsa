class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0;
        int start = 0;
        for (auto i : nums){
            if (i < target){
                start++;
            }
            if (i == target){
                cnt++;
            }
        }
        vector <int> res(cnt);
        iota(res.begin(), res.end(), start);
        return res;
    }
};