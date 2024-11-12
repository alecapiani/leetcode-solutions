// 68. Text Justification
// https://leetcode.com/problems/text-justification/
// 0ms solution

class Solution {
    using vs=vector<string>;
    string buildPhrase(vs::iterator i, vs::iterator j, int len, int mw) {
        if (i < j) {
            string ret = string(*i);
            int sp = (mw-len) / distance(i,j);
            int r = (mw-len) % distance(i,j);
            while(++i <= j)
                ret += string(sp + (r-->0), ' ') + *i;
            return ret;
        }
        return *i + string(mw-j->size(), ' ');
    }
    string buildLastPhrase(vs::iterator i, vs::iterator end, int mw) {
        string ret = string(*i);
        while(++i < end)
            ret += ' ' + *i;
        return ret + string(mw-ret.size(), ' ');
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vs ret;
        auto it=words.begin(); auto jt=it;
        int len=0;
        while(jt<words.end()) {
            if (len + jt->size() + distance(it,jt) > maxWidth) {
                ret.push_back(buildPhrase(it, prev(jt), len, maxWidth));
                it = jt;
                len = 0;
            }
            else
                len += (jt++)->size();
        }
        ret.push_back(buildLastPhrase(it, jt, maxWidth));
        return ret;
    }
};