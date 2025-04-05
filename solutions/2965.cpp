// 2965. Find Missing and Repeated Values
// https://leetcode.com/problems/find-missing-and-repeated-values
// 0ms solution

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            const int n = grid.size();
            vector<bool> bs(n*n+1, false);
            int dup = -1;
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j) {
                    int k = grid[i][j];
                    if (bs[k])
                        dup = k;
                    bs[k] = true;
                }
            int miss = -1;
            for(int i=1; i<=n*n; ++i)
                if (!bs[i]) {
                    miss = i;
                    break;
                }
            return {dup, miss};
        }
    };