class Solution {
public:
    bool calcDay(int day, vector<int>& bloomDay, int m, int k){
        int cnt = 0;
        int noOfB = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++){
            if (bloomDay[i] <= day){
                cnt++;
            } else{
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        if (noOfB >= m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        long long n = bloomDay.size();
        if ((long long) m * k > n){
            return -1;
        }
        for (auto i : bloomDay){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        if (mini == maxi){
            return mini;
        }
        int ans = maxi;
        while(mini <= maxi){
            int mid = (mini + maxi) / 2;
            if (calcDay(mid, bloomDay, m, k)){
                ans = mid;
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }
        return ans;
    }
};