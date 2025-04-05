// 2503. Maximum Number of Points From Grid Queries
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries

class Solution {
    constexpr static int dir[] = {1,0,-1,0,1};
    using cell_t=tuple<int,int,int>;
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int m = grid.size(), n = grid[0].size();
        map<int, int> cnt; cnt[0]=0;
        priority_queue<cell_t, vector<cell_t>, function<bool(cell_t&,cell_t&)>> pq([](cell_t& a, cell_t& b) {
            return get<2>(a) > get<2>(b);
        }); 
        pq.emplace(0,0,grid[0][0]); grid[0][0] = -1;
        while(!pq.empty()) {
            auto [r,c,mv] = pq.top(); pq.pop();
            cnt[mv]++;
            for(int i=0; i<4; ++i) {
                int rn = r + dir[i], cn = c + dir[i+1];
                if (rn >= 0 && rn < m && cn >= 0 && cn < n && grid[rn][cn] >= 0) {
                    pq.emplace(rn, cn, max(mv, grid[rn][cn]));
                    grid[rn][cn] = -1;
                }
            }
        }
        for(auto it = cnt.begin(); it != prev(cnt.end()); ++it)
            next(it)->second += it->second;
        vector<int> ret(queries.size());
        transform(queries.begin(), queries.end(), ret.begin(), [&](int q) {
            return prev(cnt.lower_bound(q))->second;
        });
        return ret;
    }
};