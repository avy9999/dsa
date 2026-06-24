class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // better approach
        unordered_map <int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int c = target - nums[i];
            if (mp.find(c) != mp.end()){
                return {mp[c], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};