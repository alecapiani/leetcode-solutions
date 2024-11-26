// 773. Sliding Puzzle
// https://leetcode.com/problems/sliding-puzzle
// 0ms solution

static unordered_map<int,int> mp;
static constexpr int compress(int v[6]) {
    int r=0;
    for(int i=0; i<6; ++i)
        r = r * 8 + v[i];
    return r;
}

static const int _ = []{
    int t[] = {1,2,3,4,5,0};
    function<void(int,int)> rec = [&](int p, int d) {
        int x = compress(t);
        auto it = mp.find(x);
        if (it != mp.end() && it->second <= d)
            return;
        mp[x] = d;
#define DO(n) { t[p] = t[n]; t[n] = 0; rec(n,d+1); t[n] = t[p]; }
        if (p >= 3)           DO(p-3)
        else                  DO(p+3)
        if (p != 2 && p != 5) DO(p+1)
        if (p != 0 && p != 3) DO(p-1)
        t[p] = 0;
    };
    rec(5,0);
    return 'g';
}();

class Solution {
    inline constexpr int toint(vector<vector<int>>& board) {
        int r=0;
        for(int i=0; i<2; ++i)
            for(int j=0; j<3; ++j)
                r = 8 * r + board[i][j];
        return r;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        auto it = mp.find(toint(board));
        return it == mp.end() ? -1 : it->second;
    }
};