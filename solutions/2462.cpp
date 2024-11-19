// 2461. Maximum Sum of Distinct Subarrays With Length K
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// 0ms solution

#define MN 100000
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret=0, sum=0;
        bitset<MN+1> bs; bs.reset();
        for(int i=0,j=0; i<nums.size(); ++i) {
            if (bs[nums[i]])
                do {
                    bs[nums[j]] = false;
                    sum -= nums[j];
                } while(nums[j++] != nums[i]);
            bs[nums[i]] = true;
            sum += nums[i];
            if (i-j+1 == k) {
                ret = max(ret, sum);
                sum -= nums[j];
                bs[nums[j++]] = false;
            }
        }
        return ret;
    }
};
