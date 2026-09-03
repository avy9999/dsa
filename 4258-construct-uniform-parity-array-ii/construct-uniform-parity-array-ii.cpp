class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int even = 0;
        int ev = 1e9;
        int od = 1e9 - 1;
        for (auto i : nums1){
            if (i % 2 == 0){
                ev = min(ev, i);
                even++;
            } else{
                od = min(od, i);
                odd++;
            }
        }
        if (even == 0 || odd == 0) return true;
        if (od < ev) return true;
        return false;
    }
};