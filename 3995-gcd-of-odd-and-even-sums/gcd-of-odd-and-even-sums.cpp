class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0, sumOdd = 0;
        for (int i = 1; i <= 2*n; i++){
            if (i % 2 == 0) sumEven += i;
            else sumOdd += i;
        }
        while(sumEven > 0 && sumOdd > 0) {
            if(sumEven > sumOdd) {
                sumEven = sumEven % sumOdd;
            }
            else {
                sumOdd = sumOdd % sumEven;
            }
        }
        if(sumEven == 0) {
            return sumOdd;
        }
        return sumEven;
    }
};