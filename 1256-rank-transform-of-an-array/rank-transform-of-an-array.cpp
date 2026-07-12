class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> cp = arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        int index = 1;
        for (auto i : arr){
            if(rank.find(i) != rank.end()){
                continue;
            } else{
                rank[i] = index;
                index++;
            }
        }
        for (int i = 0; i < cp.size();   i++){
            cp[i] = rank[cp[i]];
        }
        return cp;
    }
};