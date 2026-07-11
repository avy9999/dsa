class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector <int> temp(n+1, 0);
        for (auto i : citations){
            temp[min(i, n)]++;
        }
        int total = 0;
        for (int i = n; i >= 0; i--){
            total += temp[i];
            if (total >= i){
                return i;
            }
        }
        return 0;
    }
};