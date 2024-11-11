// 3097. Shortest Subarray With OR at Least K II
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        array<int, INT_WIDTH> cnt; cnt.fill(0);
        int orv = 0;
        int ret = INT_MAX;
        for(auto it=nums.begin(), jt=nums.begin(); ret > 1 && jt < nums.end(); ++jt) {
            for(int i=0; 1<<i <= *jt; ++i)
                cnt[i] += *jt >> i & 1;
            orv |= *jt;
            if (orv >= k) {
                while(it <= jt && orv >= k) {
                    for(int i=0; 1<<i <= *it; ++i) 
                        orv &= ~(((cnt[i] -= *it >> i & 1) == 0) << i);
                    ++it;
                }
                ret = min<int>(ret, distance(it,jt)+2);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};