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
        for (int i = 0; i < 26; i++){
            cost += ((i/8)+1)*a[i];
        }
        return cost;
    }
};