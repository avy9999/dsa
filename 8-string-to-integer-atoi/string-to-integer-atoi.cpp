class Solution {
public:
    int myAtoi(string s) {
        long long bound = 1LL << 31;
        long long num = 0;
        long long mul = 1;
        bool pos = true;
        int index = 0;
        while (index < s.size() && s[index] == ' '){
            index++;
        }
        if (isdigit(s[index])){
            num = s[index] - '0';
            mul *= 10;
        } else {
            if (s[index] == '-' || s[index] == '+'){
                pos = (s[index] == '-') ? false : true;
            } else{
                return 0;
            }
        }
        index++;
        while(isdigit(s[index])){
            num = num * mul + (s[index] -'0');
            mul = (mul == 1 && num > 0 ? mul*10 : mul*1);
            index++;
            if (num >= bound){
                num = bound;
                break;
            }
        }
        if (pos){
            if (num < bound){
                return num;
            }
            return num - 1;
        }
        return 0 - num;
    }
};