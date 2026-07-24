class Solution {
public:
    string expandFromMid(string s, int left, int right){
        int n = s.length();
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1){
            return s;
        }
        string maxStr = s.substr(0,1);
        for (int i = 0; i < n; i++){
            string odd = expandFromMid(s, i, i);
            string even = expandFromMid(s, i, i + 1);

            if (odd.length() > maxStr.length()){
                maxStr = odd;
            }

            if (even.length() > maxStr.length()){
                maxStr = even;
            }
        }
        return maxStr;
    }
};