// 2588. Count the Number of Beautiful Subarrays
// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ret=0;
        int curr=0;
        unordered_map<int, int> mp;
        for(auto&& n: nums) {
            curr ^= n;
            ret += !curr + (long long)mp[curr]++;
        }
        return ret;
    }
};