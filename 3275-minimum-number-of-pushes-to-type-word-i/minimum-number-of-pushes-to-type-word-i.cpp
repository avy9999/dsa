class Solution {
public:
    int minimumPushes(string word) {
        int a[26];
        for (auto i : word){
            a[i - 'a']++;
        }
        sort(begin(a), end(a), [](int a, int b){
            return a > b;
        });
        int cost = 0;
        int c = 0;
        for (int i = 0; i < 26; i++){
            if (c < 8){
                cost += a[i];
            } else if (c < 16){
                cost += a[i]*2;
            } else if (c < 24){
                cost += a[i]*3;
            } else{
                cost += a[i]*4;
            }
            c++;
        }
        return cost;
    }
};