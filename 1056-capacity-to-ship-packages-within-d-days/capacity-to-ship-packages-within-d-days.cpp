class Solution {
public:
    int calc(int mid, vector<int>& weights, int days){
        int cnt = 0, dayCount = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++){
            if (cnt + weights[i] <= mid){
                cnt += weights[i];
            } else{
                dayCount++;
                cnt = weights[i];
            }
        }
        dayCount++;
        if (dayCount <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini = INT_MIN;
        int maxi = 0;
        for (auto i : weights){
            maxi += i;
            mini = max(mini, i);
        }
        int low = mini, high = maxi;
        int ans = mini;
        while(low <= high){
            int mid = (low + high) / 2;
            if (calc(mid, weights, days)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};