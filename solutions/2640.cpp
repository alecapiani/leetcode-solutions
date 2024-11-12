// 2640. Find the Score of All Prefixes of an Array
// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array
// 0ms solution

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        using ll=long long;
        ll sum=0;
        int m=0;
        vector<ll> ret(nums.size());
        transform(nums.begin(), nums.end(), ret.begin(), [&sum,&m](auto& x) {
            m = max(m, x);
            return sum += m + x;
        });
        return ret;
    }
};