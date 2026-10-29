class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt[101] = {0}, res = 0, n = nums.size();
        for (int i = 0; i < nums.size(); ++i)
            if (i == 0 || nums[i] != nums[i - 1])
                cnt[nums[i]]++;
        for (int c : cnt)
            if (c == 1)
                res++;
        return res;
    }
};