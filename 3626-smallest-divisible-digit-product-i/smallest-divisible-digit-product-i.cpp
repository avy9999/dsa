class Solution {
public:
    int smallestNumber(int n, int t) {
        auto [q, r] = div(n, 10);

        int mul = t / gcd(max(q, 1), t);
        int next = ((mul + r - 1) / mul) * mul;
        if (next < 10){
            return q * 10 + next;
        }
        return (q + 1) * 10;
    }
};