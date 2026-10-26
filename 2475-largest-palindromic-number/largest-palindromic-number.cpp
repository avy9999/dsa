class Solution {
public:
    string largestPalindromic(string num) {
        string res = "";
        int freq[10];
        for (auto c : num){
            freq[c - '0']++;
        }
        int mid = -1;
        for (int i = 9; i >= 0; i--){
            if (i == 0 && res == "") freq[i] = 0;
            int t = freq[i] / 2;
            if (freq[i] - t > t && mid == -1){
                mid = i;
            }
            for (int j = 0; j < t; j++){
                res += i + '0';
            }
            freq[i] = t;
        }
        if (mid == -1 && res == ""){
            return "0";
        } else if (mid != -1){
            res += mid + '0';
        }
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < freq[i]; j++){
                res += i + '0';
            }
        }
        return res;
    }
};