class Solution {
public:
    void combination(int ind, vector<int>& a, vector<vector<int>>& res, int target, vector <int>& arr){
        if (ind == arr.size()){
            if (target == 0){
                res.push_back(a);
            }
            return;
        }
        if (arr[ind] <= target){
            a.push_back(arr[ind]);
            combination(ind, a, res, target - arr[ind], arr);
            a.pop_back();
        }
        combination(ind + 1, a, res, target, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int>> res;
        vector <int> a;
        combination(0, a, res, target, candidates);
        return res;
    }
};