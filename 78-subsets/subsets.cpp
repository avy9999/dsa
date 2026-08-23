class Solution {
public:
    void findSubset(int index, vector <int>& v, vector<int>& arr, vector<vector <int>>& res){
        if (index == arr.size()){
            res.push_back(v);
            return;
        }
        v.push_back(arr[index]);
        findSubset(index + 1, v, arr, res);
        v.pop_back();
        findSubset(index + 1, v, arr, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector <int>> res;
        vector <int> v;
        findSubset(0, v, nums, res);
        return res;
    }
};