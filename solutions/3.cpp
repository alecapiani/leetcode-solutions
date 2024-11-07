// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters
// 0ms solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<128> bs; bs.reset();
        int ret = 0;
        for (int i=0, j=0;; ++i) {
            if (bs[s[i]]) {
                ret = max(ret, i-j);
                do {
                    bs.set(s[j], false);
                } while(s[i] != s[j++]);
            }
            bs.set(s[i], true);
            if (i == s.size()) {
                ret = max(ret, i-j);
                break;
            }
        }
        return ret;
    }
};