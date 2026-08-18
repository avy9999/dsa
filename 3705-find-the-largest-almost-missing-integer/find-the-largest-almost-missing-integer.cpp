class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        int n = nums.size();
        for (auto i : nums){
            mp[i]++;
        }
        
        int ans = -1;
        if (k == 1){
            for (const auto& [key, value] : mp){
                if (value == 1){
                    ans = max(ans, key);
                }
            }
        } else if(k == n){
            for (const auto& [key, value] : mp){
                ans = max(ans, key);
            }
        } else{
            if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1){
                ans = max(nums[0], nums[n - 1]);
            } else{
                if (mp[nums[0]] == 1){
                    ans = nums[0];
                }
                if (mp[nums[n - 1]] == 1){
                    ans = nums[n - 1];
                }
            }
        }
        return ans;
    }
};