// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals
// 0ms solution

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        const int n = nums.size();
        int ret = 0;
        for(int i=1; i < 1<<n; ++i) {
            int p = 0;
            for(int j=0; i>>j; ++j)
                p ^= (i>>j&1) * nums[j];
            ret += p;
        }
        return ret;
    }
};