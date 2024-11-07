// 2275. Largest Combination With Bitwise AND Greater Than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

#define BIT_WIDTH 24 // ceil(log2(1e7))

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        array<int, BIT_WIDTH> cnt;
        for(auto &&x: candidates)
            for(int i = 0; x > 0; ++i, x >>= 1)
                cnt[i] += x & 1;
        return *max_element(cnt.begin(), cnt.end());
    }
};