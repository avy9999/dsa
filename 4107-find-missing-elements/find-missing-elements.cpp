class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <int> ans;
        set<int>st(nums.begin(),nums.end());
        for (int i = nums[0]; i <= nums[nums.size() - 1]; i++){
            if (st.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};