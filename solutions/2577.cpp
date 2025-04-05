// 2577. Minimum Time to Visit a Cell In a Grid
// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid
class Solution {
    using cell_t=tuple<int,int,int>;
    class cmp_t {
    public:
        bool operator() (cell_t& a, cell_t& b) { return get<2>(a) > get<2>(b); }
    };
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) // not solvable
            return -1;
        int dir[]={1,0,-1,0,1};
        priority_queue<cell_t, vector<cell_t>, cmp_t> pq;
        pq.emplace(0,0,0);
        while(1) {
            auto [r1,c1,d1] = pq.top(); pq.pop();
            for(int i=0; i<4; ++i) {
                int r2=r1+dir[i], c2=c1+dir[i+1];
                if (r2 < 0 || r2 >= m || c2 < 0 || c2 >= n || grid[r2][c2] == -1)
                    continue;
                int d2 = grid[r2][c2] <= d1+1 ? d1+1 : grid[r2][c2] + ((d1-grid[r2][c2])&1^1);
                if (r2 == m-1 && c2 == n-1)
                    return d2;
                pq.emplace(r2,c2,d2);
                grid[r2][c2] = -1;
            }
        }
        return 'u';
    }
};