class Solution {
public:
    bool palindrome(string &s, int l, int r){
        while(l <= r){
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int checkPartition(int i, int n, string &s, vector <int>& dp){
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for (int j = i; j < n; ++j){
            if (palindrome(s, i, j)){
                int cost = 1 + checkPartition(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector <int> dp(n, -1);
        return checkPartition(0, n, s, dp) - 1;
    }
};