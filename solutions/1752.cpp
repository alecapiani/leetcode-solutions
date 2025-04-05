// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated
// 0ms solution

class Solution {
    public:
        bool check(vector<int>& nums) {
            bool pivot_found = false;
            for(int i=0; i<nums.size()-1; ++i)
                if (nums[i] > nums[i+1]) {
                    if (pivot_found)
                        return false;
                    pivot_found = true;
                }
            return pivot_found ? nums.front() >= nums.back() : true;
        }
    };