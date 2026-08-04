class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map <int, int> mp;
        int mini = 101, maxi = 0;
        for (auto x : nums){
            mp[x]++;
            maxi = max(x, maxi);
            mini = min(x, mini);
        }
        vector <int> ans;
        for (int i = mini; i <= maxi; i++){
            if (mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};