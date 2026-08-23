class Solution {
public:
    void findSubset(int i, vector <int>& v, vector<int>& arr, vector<vector <int>>& res){
        if (i == arr.size()){
            res.push_back(v);
            return;
        }
        v.push_back(arr[i]);
        findSubset(i + 1, v, arr, res);
        v.pop_back();
        int idx = i + 1;
        while(idx < arr.size() && arr[idx] == arr[idx - 1]){
            idx++;
        }
        findSubset(idx, v, arr, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> res;
        vector <int> v;
        findSubset(0, v, nums, res);
        return res;
    }
};