// 3315. Construct the Minimum Bitwise Array II
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
// 0ms solution
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/solutions/6026658/c-one-line-solution-explained-arithmetically/

/* 
map(x:nums) -> get lowest clear bit from x, reset previous bit from x
if x>2 and trailing bit manipulation is supported,
the generated asm should be:
    blci eax, edi // r = x | ~(x+1)
    sar  eax      // r >>= 1
    and  eax, edi // r &= x
    ret
if not supported:
    mov eax, -2
    sub eax, edi
    or  eax, edi
    sar eax
    and eax, edi
    ret
*/
#pragma GCC target("bmi,tbm")
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ret(nums.size());
        transform(nums.begin(), nums.end(), ret.begin(), [](int x){
            return x > 2 ? x & ((x | ~(x+1)) >> 1): -1;
        });
        return ret;
    }
};