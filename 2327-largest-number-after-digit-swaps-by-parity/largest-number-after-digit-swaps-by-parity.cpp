class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        priority_queue <int> o;
        priority_queue <int> e;
        while (num > 0){
            int d = num % 10;
            num /= 10;
            if (d % 2 == 0){
                e.push(d);
            } else{
                o.push(d);
            }
        }
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            if ((s[i] - '0') % 2 == 0){
                res = res * 10 + e.top();
                e.pop();
            } else{
                res = res * 10 + o.top();
                o.pop();
            }
        }
        return res;
    }
};