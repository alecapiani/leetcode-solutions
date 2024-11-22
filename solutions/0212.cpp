#define GET(b, x) (b & 1U << (x))
#define SET(b, x) b |= 1U << (x)
#define RESET(b, x) b &= ~(1U << (x))

class Solution {
    struct node {
        uint32_t next=0;
        list<struct node> values;
        string *word=nullptr;
    } root;

    void build(vector<string>& ws) {
        for(auto&& w: ws) {
            struct node *ptr = &root;
            for(auto&& c: w) {
                auto it = ptr->values.begin();
                int k=c-'a';
                for(int i=0; i<k; ++i)
                    if (GET(ptr->next, i))
                        ++it;
                if (!GET(ptr->next, k)) {
                    it = ptr->values.insert(it, node());
                    SET(ptr->next, k);
                }
                ptr = &*it;
            }
            ptr->word = &w;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size(), n=board[0].size();
        build(words);
        vector<string> ret;
        int dir[5] = {0,1,0,-1,0};
        function<void(int,int,struct node *)> solve = [&](int i, int j, struct node *ptr) {
            int c=board[i][j]-'a';
            if (!GET(ptr->next, c))
                return;
            board[i][j] = 0;
            auto it=ptr->values.begin();
            for(int k=0; k<c; ++k)
                if (GET(ptr->next, k))
                    ++it;
            if (it->word != nullptr) {
                ret.push_back(*(it->word));
                it->word = nullptr;
            }
            for(int k=0; k<4; ++k) {
                int rn = i+dir[k], cn=j+dir[k+1];
                if (rn >= 0 && rn < m && cn >= 0 && cn < n && board[rn][cn]) 
                    solve(rn, cn, &*it);
            }
            if (it->next == 0) {
                RESET(ptr->next, c);
                ptr->values.erase(it);
            }
            board[i][j] = c+'a';
        };
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                solve(i, j, &root);
        return ret;
    }
};