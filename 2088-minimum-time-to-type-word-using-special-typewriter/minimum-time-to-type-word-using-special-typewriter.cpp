class Solution {
public:
    int minTimeToType(string word) {
        char cur = 'a';
        int time = 0;
        int n = word.size();
        for (int i = 0; i < n; i++){
            time += min(abs(cur - word[i]), 26 - abs(cur - word[i]));
            cur = word[i];
        }
        time += n;
        return time;
    }
};