// 1593. Split a String Into the Max Number of Unique Substrings
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings
// 0ms solution

class Solution {
    unordered_set<string> st;
    int ret = 0;
    void solve(const string &s, const int offset, const int cnt) {
        if (offset == s.size()) {
            ret = cnt;
            return;
        }
        for(int i=offset; i < s.size()+min(cnt-ret, 0); ++i) { 
            // stop iterating if is impossible to find a better solution
            // (not enough characters left assuming each character left could form a unique substring of length == 1)
            auto it = st.insert(s.substr(offset,i-offset+1));
            if (it.second) {
                solve(s, i+1, cnt+1);
                st.erase(it.first); // rehash won't happen, set is reserved to contain s.size() different substrings
            }
        }
    }
public:
    int maxUniqueSplit(const string s) {
        st.reserve(s.size());
        solve(s, 0, 0);
        return ret;
    }
};