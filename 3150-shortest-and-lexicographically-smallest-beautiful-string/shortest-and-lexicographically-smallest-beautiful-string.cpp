class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.size();

        int o = 0;
        int l = 0;

        for (int i = 0; i < n; ++i){
            if (s[i] == '1') o++;

            while (o > k){
                if (s[l] == '1'){
                    o--;
                }
                l++;
            }

            if (o == k){
                while(l < i && s[l] == '0') l++;

                string c = s.substr(l, i - l + 1);
                if (res == "" || c.size() < res.size() || (c.size() == res.size() && c < res)) res = c;
            }
        }
        return res;
    }
};