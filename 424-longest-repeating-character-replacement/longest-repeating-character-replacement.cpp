class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (n == 0 || k < 0) return 0;
        int max_length = 0;
        int max_freq = 0;
        int left = 0;
        vector<int> freq(26, 0);
        for (int right = 0; right < n; right++){
            int idx = s[right] - 'A';
            freq[idx]++;
            max_freq = max(max_freq, freq[idx]);
            int l = right - left + 1;
            if (l - max_freq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            l = right - left + 1;
            max_length = max(max_length, l);
        }
        return max_length;
    }
};