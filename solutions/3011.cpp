// 3011. Find if Array Can Be Sorted
// https://leetcode.com/problems/find-if-array-can-be-sorted/
// 0ms solution

class Solution {
public:
    __attribute__ ((target ("popcnt")))
    bool canSortArray(vector<int>& nums) {
        int prevcnt=0, prevmax=0;
        int cmax=0;
        for(auto&& x: nums) {
            int cnt = __builtin_popcount(x);
            if (x < prevmax)
                return false;
            if (cnt != prevcnt)
                if (x < (prevmax = cmax))
                    return false;
            cmax = max(cmax, x);
            prevcnt = cnt;
        }
        return true;
    }
};