class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int gcd=1;
        for (int i=nums[0]; i>0; i--){
            if (nums[nums.size()-1]%i==0 && nums[0]%i==0){
                gcd=i;
                break;
            }
        }
        return gcd;
    }
};