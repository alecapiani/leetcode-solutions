// 3093. Longest Common Suffix Queries
// https://leetcode.com/problems/longest-common-suffix-queries

class Solution {
    struct node {
        int next[26] = {0};
        int idx,len;
        node(int idx = UINT16_MAX, int len = UINT16_MAX) {
            this->idx = idx;
            this->len = len;
        }
    };
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<struct node> trie { node() };
        auto insert = [&trie](string& w, int idx) { 
            if (trie[0].len > w.size())
                trie[0].idx = idx, trie[0].len = w.size();
            int n=0;
            for(auto it=w.rbegin(); it != w.rend(); ++it) {
                int k=*it-'a';
                if(!trie[n].next[k]) {
                    n = trie[n].next[k] = trie.size();
                    trie.push_back(node(idx, w.size()));
                    continue;
                }
                n = trie[n].next[k];
                if (trie[n].len > w.size()) 
                    trie[n].idx = idx, trie[n].len = w.size();
            }
        };
        auto get = [&trie](string& w) -> int {
            int n=0;
            for(auto it=w.rbegin(); it != w.rend(); ++it) {
                int k=*it-'a';
                if (!trie[n].next[k])
                    return trie[n].idx;
                n = trie[n].next[k];
            }
            return trie[n].idx;
        };
        for(int i=0; i<wordsContainer.size(); ++i)
            insert(wordsContainer[i], i);
        vector<int> ret;
        for(auto&& w: wordsQuery)
            ret.push_back(get(w));
        return ret;
    }
};