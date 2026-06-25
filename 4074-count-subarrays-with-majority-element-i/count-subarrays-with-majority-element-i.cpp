class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int cnt_target = 0;
            for (int j = i; j < n; j++){
                if (nums[j] == target){
                    cnt_target++;
                }
                if (2*(cnt_target) > j - i + 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};