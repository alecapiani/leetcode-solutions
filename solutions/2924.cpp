// 2924. Find Champion II
// https://leetcode.com/problems/find-champion-ii
// 0ms solution

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        using vi=vector<int>;
        vi indeg(n, 0);
        for(auto&& e: edges)
            indeg[e[1]]++;
        int ret = -1;
        for(int i=0; i<n; ++i)
            if (indeg[i] == 0) {
                if (ret > -1)
                    return -1;
                ret = i;
            }
        return ret;
    }
};