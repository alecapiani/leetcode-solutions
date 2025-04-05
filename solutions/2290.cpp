// 2290. Minimum Obstacle Removal to Reach Corner
// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner

class Solution {
    using cell_t=tuple<int,int,int>;
    class cmp_t {
    public:
        bool operator()(const cell_t& a, const cell_t& b) {return get<2>(a) > get<2>(b); }
    };
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[] = {1,0,-1,0,1};
        priority_queue<cell_t, vector<cell_t>, cmp_t> pq;
        pq.emplace(0,0,0);
        while(1) {
            auto [r,c,d] = pq.top(); pq.pop();
            for(int i=0; i<4; ++i) {
                int nr=r+dir[i], nc=c+dir[i+1];
                if (nr == m-1 && nc == n-1)
                    return d;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == -1)
                    continue;
                pq.emplace(nr,nc,d+grid[nr][nc]);
                grid[nr][nc] = -1;
            }
        }
        return 'u';
    }
};