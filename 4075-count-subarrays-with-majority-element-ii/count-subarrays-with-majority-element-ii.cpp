class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                nums[i] = 1;
            } else{
                nums[i] = -1;
            }
        }

        vector <int> prefixSum(n);
        prefixSum[0]= nums[0];
        for (int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        int shift = n;
        vector <int> freq(2 * n + 1, 0);
        freq[shift] = 1;

        long long valid = 0;
        int lastSum = 0;
        for (int i = 0; i < n; i++){
            if (prefixSum[i] > lastSum){
                valid += freq[lastSum + shift];
            } else{
                valid -= freq[prefixSum[i] + shift];
            }

            cnt+=valid;
            freq[prefixSum[i] + shift]++;
            lastSum = prefixSum[i];
        }

        return cnt;
    }
};