class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map <int, int> mp;
        for (auto x : planks){
            mp[x]++;
        }
        sort(planks.begin(), planks.end());
        unordered_map <int, int> p;
        int count = 0;
        for (auto it1 = mp.begin(); it1 != mp.end(); ++it1){
            int l1 = it1 -> first;
            int c1 = it1 -> second;

            p[l1 * 2] += c1 / 2;
            auto it2 = it1;
            ++it2;
            for (; it2 != mp.end(); ++it2){
                int l2 = it2 -> first;
                int c2 = it2 -> second;

                int sum = l1 + l2;
                p[sum] += min(c1, c2);
            }
        }
        for (auto& [h, c] : mp){
            count = max(count, c + p[h]);
        }

        for (auto& [h, c] : p){
            if (mp.find(h) == mp.end()){
                count = max(count, c);
            }
        }
        return count;
    }
};