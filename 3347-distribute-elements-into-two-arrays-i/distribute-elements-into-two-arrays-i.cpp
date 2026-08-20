class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> res;
        vector <int> v;
        res.emplace_back(nums[0]);
        v.emplace_back(nums[1]);
        for (int i = 2; i < n; i++){
            if (res.back() > v.back()){
                res.emplace_back(nums[i]);
            } else{
                v.emplace_back(nums[i]);
            }
        }
        for (int i = 0; i < v.size(); i++){
            res.emplace_back(v[i]);
        }
        return res;
    }
};