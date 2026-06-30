class Solution {
public:
    string largestOddNumber(string num) {
        reverse(num.begin(), num.end());
        bool odd = false;
        string res = "";
        for (auto i : num){
            if ((i - '0') % 2){
                odd = true;
            }
            if (odd) res+=i;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};