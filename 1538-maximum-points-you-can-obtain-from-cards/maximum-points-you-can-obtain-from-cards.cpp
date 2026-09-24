class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector <int> pref(n + 1, 0);
        pref[0] = 0;
        for (int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + cardPoints[i];
        }
        int m = 0;
        for (int i = 0; i <= k; i++){
            m = max(m, pref[i] + pref[n] - pref[n - (k - i)]);
        }
        return m;
    }
};