class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num * 9 < sum) return "";
        string s = "";
        while(sum > 9){
            s += '9';
            num--;
            sum -= 9;
        }
        s += sum + '0';
        num--;
        while(num--){
            s += '0';
        }
        return s;
    }
};