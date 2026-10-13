class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) > abs(b);
        });
        long long sum = 0;
        int n = nums.size();
        int i = 0;
        for (i; i < (n + 1)/ 2; i++){
            sum += nums[i] * nums[i];
        }
        for (i; i < n; i++){
            sum -= nums[i] * nums[i];
        }
        return sum;
    }
};