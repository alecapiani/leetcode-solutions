// 3254. Find the Power of K-Size Subarrays I
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ret;
        int cnt=1, last=-1;
        int i;
        for(i=0; i<min(k-1,n); ++i) {
            cnt = nums[i] == last+1 ? cnt+1 : 1;
            last = nums[i];
        }
        while(i<n) {
            cnt = nums[i] == last+1 ? cnt+1 : 1;
            last = nums[i];
            ret.push_back(cnt >= k ? last : -1);
            ++i;
        }
        return ret;
    }
};