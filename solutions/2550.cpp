// 2550. Count Collisions of Monkeys on a Polygon
// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon
// 0ms solution

#pragma GCC target("lzcnt")
#define MOD ((int)1e9+7)
class Solution {
public:
    int monkeyMove(int n) {
        // 2^n - 2
        long long ret=2;
        int hi = INT_WIDTH - __builtin_clz(n) - 1;
        for(int i=hi-1; i>=0; --i)
            ret = ((ret * ret) << (n >> i & 1)) % MOD;
        return (ret + MOD - 2) % MOD;
    }
};