// 472. Concatenated Words
// https://leetcode.com/problems/concatenated-words

class Solution {
    struct node {
        array<int, 26> next;
        bool terminal = false;
        node() { next.fill(-1); }
    };
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<struct node> buffer { node() };
        auto insert = [&](string& w) {
            int n = 0;
            for(auto&& c: w) {
                int k = c-'a';
                if (buffer[n].next[k] == -1) {
                    buffer[n].next[k] = buffer.size();
                    buffer.emplace_back();
                }
                n = buffer[n].next[k];
            }
            buffer[n].terminal = true;
        };
        function<bool(string&, int)> isconcat = [&](string& w, int idx) {
            if (idx == w.size())
                return true;
            int n = 0;
            for(int i=idx; i<w.size(); ++i) {
                int k = w[i]-'a';
                if (buffer[n].next[k] == -1)
                    return false;
                n = buffer[n].next[k];
                if (buffer[n].terminal && isconcat(w, i+1))
                    return true;
            }
            return false;
        };

        sort(words.begin(), words.end(), [](auto& a, auto& b) { return a.size() < b.size(); });
        vector<string> ret;
        for(auto&& w: words) {
            if (isconcat(w, 0))
                ret.push_back(w);
            else
                insert(w);
        }
        return ret;
    }
};