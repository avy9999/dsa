class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int neg = nums[0] * nums[1] * nums[n - 1];
        int pos = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return (neg > pos) ? neg : pos;
    }
};