// 1584. Min Cost to Connect All Points
// https://leetcode.com/problems/min-cost-to-connect-all-points

#define ALL(v) (v).begin(),(v).end()
typedef vector<int> vi;
class Solution {
    static inline int dist(vi& a, vi& b) { 
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        list<pair<vector<vi>::iterator, int>> pq;
        for_each(next(points.begin()), points.end(), [&pq](auto& p){ pq.emplace_back(&p, INT_MAX); });
        auto n = points.begin();
        int ret = 0;
        while(!pq.empty()) {
            for_each(ALL(pq), [&n](auto& p){ p.second = min(p.second, dist(*n, *p.first)); });
            auto m = min_element(ALL(pq), [](auto& a, auto &b){ return a.second < b.second; });
            n = m->first;
            ret += m->second;
            pq.erase(m);
        }
        return ret;
    }
};