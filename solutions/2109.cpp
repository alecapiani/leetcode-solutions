// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        auto it = spaces.begin();
        int i;
        for(i=0; it < spaces.end(); ++i) {
            if (i == *it) {
                ret += ' ';
                ++it;
            }
            ret += s[i];
        }
        while(i < s.size())
            ret += s[i++];
        return ret;
    }
};