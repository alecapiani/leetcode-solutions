// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

typedef vector<int> vi;

class Solution {
    static constexpr char dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vi> dist;
    constexpr inline int discover(vector<vi>& v, short r, short c) {
        int m = size(v), n = size(v[0]);
        if (dist[r][c])
            return dist[r][c];
        dist[r][c] = 1;
        for(int i=0; i<4; ++i) {
            short r1 = r + Solution::dir[i][0], c1 = c + Solution::dir[i][1];
            if (r1 >= 0 && r1 < m && c1 >= 0 && c1 < n && v[r][c] > v[r1][c1])
                dist[r][c] = max(dist[r][c], 1 + discover(v, r1, c1));
        }
        return dist[r][c];
}

public:
    constexpr inline int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int m = size(matrix), n = size(matrix[0]);
        dist.resize(m, vi(n, 0));
        int ret = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                ret = max(ret, discover(matrix, i, j));
        return ret;
    }
};