class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int, int>> gp;
        long long totalCost = 0;
        for (int i = 0; i < n; i++){
            gp.push_back({nums[i], cost[i]});
            totalCost += cost[i];
        }
        sort(gp.begin(), gp.end());

        long long pSum = 0;
        long long mid = 0;

        for (auto [value, x] : gp){
            pSum += x;
            if(2 * pSum >= totalCost){
                mid = value;
                break;
            }
        }

        long long m = 0;
        for (auto [value, x] : gp){
            m += 1LL * abs(value - mid) * x;
        }
        return m;
    }
};