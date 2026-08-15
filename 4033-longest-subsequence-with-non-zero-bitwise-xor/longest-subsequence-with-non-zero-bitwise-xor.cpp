class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int m = 0;
        int x = 0;
        for (auto i : nums){
            m = max(m, i);
            x = x ^ i;
        }
        if (m == 0){
            return 0;
        }
        if (x == 0) return nums.size() - 1;
        return nums.size();
    }
};