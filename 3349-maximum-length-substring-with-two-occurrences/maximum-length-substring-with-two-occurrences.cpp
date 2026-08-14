class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map <char, int> freq;
        int index = 0;
        int i = 0;
        int len = 0;
        while(i < s.size()){
            if (freq.find(s[i]) == freq.end()){
                freq[s[i]]++;
                i++;
                len = max(len, i - index);
            } else {
                if (freq[s[i]] > 1){
                    while(s[index] != s[i]){
                        freq[s[index]]--;
                        index++;
                    }
                    index++;
                    i++;
                    len = max(len, i - index);
                } else{
                    freq[s[i]]++;
                    i++;
                    len = max(len, i - index);
                }
            }
        }
        return len;
    }
};