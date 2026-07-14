class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        long long ans = 0;
        while (low <= high){
            long long mid = (low + high) >> 1;
            long long children = 0;
            for (auto p : candies){
                children += p / mid;
            }
            if (children >= k){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return ans;
    }
};