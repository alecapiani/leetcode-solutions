// 140. Word Break II
// https://leetcode.com/problems/word-break-ii
// 0ms solution

#define TERMINAL 31
#define GET(b, x) (b & 1U << (x))
#define SET(b, x) b |= 1U << (x)

class Solution {
    struct node {
        uint32_t next = 0;
        list<struct node> values;
    } root;
    void build(vector<string>& ws) {
        for(auto&& w: ws) {
            struct node *ptr = &root;
            for(auto&& c: w) {
                auto it = ptr->values.begin();
                for(int i=0; i<c-'a'; ++i)
                    if (GET(ptr->next, i))
                        ++it;
                if (!GET(ptr->next, c-'a')) {
                    it = ptr->values.insert(it, node());
                    SET(ptr->next, c-'a');
                }
                ptr = &*it;
            }
            SET(ptr->next, TERMINAL);
        }
    }
    vector<string> ret;
    char temp[64];
    void solve(string::iterator it, string::iterator end, int idx, struct node *ptr) {
        if (it == end) {
            if (GET(ptr->next, TERMINAL)) {
                temp[idx] = 0;
                ret.push_back(string(temp));
            }
            return;
        }
        if (GET(ptr->next, TERMINAL)) {   
            temp[idx] = ' ';
            solve(it, end, idx+1, &root);
        }

        if (!GET(ptr->next, *it-'a'))
            return;
        auto lit = ptr->values.begin();
        for(int i=0; i<*it-'a'; ++i)
            if (GET(ptr->next, i))
                ++lit;
        temp[idx] = *it;
        solve(next(it), end, idx+1, &*lit);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        build(wordDict);
        solve(s.begin(), s.end(), 0, &root);
        return ret;
    }
};