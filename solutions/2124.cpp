// 2124. Check if All A's Appears Before All B's
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs
// 0ms solution

class Solution {
public:
    bool checkString(string s) {
        bool b_found = false;
        for(auto&& c: s) {
            if (c == 'a' && b_found)
                return false;
            b_found |= c == 'b';
        }
        return true;
    }
};