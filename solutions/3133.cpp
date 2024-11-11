// 3133. Minimum Array End
// https://leetcode.com/problems/minimum-array-end/
// 0ms solution

class Solution {
public:
    long long minEnd(int n, int x) {
        long long ret = 0;
        for(int i=0, j=0; 1<<i <= n-1; ++j) {
            if (~x & 1LL<<j) {
                ret |= ((n-1)>>i & 1LL) << j;
                ++i;
            }
        }
        return ret | x;
    }
};