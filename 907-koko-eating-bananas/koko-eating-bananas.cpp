class Solution {
public:
    long long calculateHours(vector<int>& piles, int hour){
        long long totalHours = 0;
        for (auto p : piles){
            totalHours += (p + hour - 1) / hour;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = max_pile;
        int ans = max_pile;
        while(low <= high){
            int mid = (low + high) / 2;
            long long total = calculateHours(piles, mid);

            if (total <= (long long) h){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
};