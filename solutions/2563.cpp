// 2563. Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs

class Solution {
    long long countLowerPairs(vector<int>& v, int x) {
        long long ret=0;
        for(auto it=v.begin(), jt=prev(v.end()); it < jt; ) {
            if (*it+*jt < x) 
                ret += distance(it++,jt);
            else
                --jt;
        }
        return ret;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countLowerPairs(nums, upper+1) - countLowerPairs(nums, lower);
    }
};