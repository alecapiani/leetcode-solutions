// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// 0ms solution

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