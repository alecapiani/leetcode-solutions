// 3342. Find Minimum Time to Reach Last Room II
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii

class Solution {
    // r,c, time, move cost
    using q_t=tuple<short,short,int,bool>;
    class cmp_t {
    public:
        bool operator() (q_t& a, q_t& b) { return get<2>(a) > get<2>(b); }
    };
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        const short dir[] = {1,0,-1,0,1};
        priority_queue<q_t, vector<q_t>, cmp_t> pq;
        pq.emplace(0,0,0,0);
        while(1) {
            auto [r,c,t,mt] = pq.top(); pq.pop();
            for(int i=0; i<4; ++i) {
                short rv=r+dir[i], cv=c+dir[i+1];
                if (rv < 0 || rv >= m || cv < 0 || cv >= n || moveTime[rv][cv] == -1)
                    continue;
                int tv = max(moveTime[rv][cv], t)+mt+1;
                if (rv == m-1 && cv == n-1)
                    return tv;
                pq.emplace(rv,cv,tv,mt^1);
                moveTime[rv][cv] = -1;
            }
        }
        return -1;
    }
};