class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = -1;
        int last = INT_MIN;
        int cnt = 0;

        for (int i = 0; i < n; i++){
            if (nums[i] - 1 == last){
                last = nums[i];
                cnt++;
            } else if (nums[i] != last){
                cnt = 1;
                last = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};