class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector <int> prefixGcd(nums.size());
        int mx=nums[0];
        for (int i=0; i<nums.size(); i++){
            mx=max(nums[i], mx);
            prefixGcd[i]=gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l=0;
        int r=prefixGcd.size()-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};