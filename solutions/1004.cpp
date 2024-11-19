// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii
// 0ms solution

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret=0, n=nums.size();
        int cnt=0;
        for(int i=0, j=0; i<n; ++i) {
            cnt += 1-nums[i];
            while(cnt > k)
                cnt += nums[j++]-1;
            ret = max(ret, i-j+1);
        }
        return ret;
    }
};