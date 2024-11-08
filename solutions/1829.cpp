// 1829. Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query
// 0ms solution
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        vector<int> ret(n);
        int mask = (1 << maximumBit) - 1;
        for(int i=0, x=0; i<n; ++i) {
            x ^= nums[i];
            ret[n-i-1] = ~x & mask;
        }
        return ret;
    }
};