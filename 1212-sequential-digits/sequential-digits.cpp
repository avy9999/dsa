class Solution {
public:
    inline static int s[45];
    inline static bool init = []() {
        int n = 0;
        for (int i = 1; i < 10; i++){
            s[n++] = i;
        }
        for (int i = 0; i < n; i++){
            int d = s[i] % 10;
            if (d < 9) s[n++] = (s[i] * 10) + d + 1;
        }
        return 0;
    }();

    vector<int> sequentialDigits(int low, int high) {
        vector <int> res;
        for (auto &x : s){
            if (x >= low && x <= high){
                res.push_back(x);
            }
        }
        return res;
    }
};