// 1178. Number of Valid Words for Each Puzzle
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle

class Solution {
    struct node {
        struct node *next[26] = {0};
        int cnt = 0;
    } root;

    void insert(string& w) {
        bitset<26> bs; bs.reset();
        for (auto&& c: w)
            bs.set(c-'a');
        auto ptr = &root;
        for(int i=0; i<26; ++i)
            if (bs[i])
                ptr = ptr->next[i] ? ptr->next[i] : ptr->next[i] = new node();
        ptr->cnt++;
    }
    
    int count(string& w, int idx, struct node *ptr, char first, bool hasFirst) {
        int ret = 0;
        if (hasFirst)
            ret += ptr->cnt;
        for(int i=idx; i<w.size(); ++i)
            if (ptr->next[w[i]-'a'])
                ret += count(w, i+1, ptr->next[w[i]-'a'], first, hasFirst | (w[i] == first));
        return ret;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        for(auto&& w: words)
            insert(w);
        vector<int> ret;
        for(auto&& w: puzzles) {
            char first = w[0];
            sort(w.begin(), w.end());
            ret.push_back(count(w, 0, &root, first, false));
        }
        return ret;
    }
};