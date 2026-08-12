class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int index = 0;
        while(index < n){
            unordered_map <int, int> mp;
            int j = index;
            int i = index;
            while(j < n){
                if (mp[nums[j]] < k){
                    mp[nums[j]]++;
                    ans = max(ans, j - i + 1);
                    j++;
                } else{
                    while(i < j){
                        if (nums[i] != nums[j]){
                            mp[nums[i]]--;
                            i++;
                        } else{
                            mp[nums[i]]--;
                            i++;
                            break;
                        }
                    }
                    ans = max(ans, j - i + 1);
                }
                index++;
            }
        }
        return ans;
    }
};