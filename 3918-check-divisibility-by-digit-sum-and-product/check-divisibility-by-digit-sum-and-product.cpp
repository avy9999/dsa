class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int num = n;
        while(num > 0){
            sum += num % 10;
            mul *= num % 10;
            num /= 10;
        }
        return n % (sum + mul) == 0;
    }
};