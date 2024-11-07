// 2293. Min Max Game
// https://leetcode.com/problems/min-max-game
// 0ms solution

typedef vector<int> vi;
template <class T> using comparison_t = T const &(T const&, T const&);

class Solution {
    int solve(vi::iterator begin, vi::iterator end, comparison_t<int> cmp) {
        if (begin == end) return *begin;
        auto m = begin; advance(m, distance(begin, end) / 2);
        return cmp(solve(begin, m, min<int>), solve(next(m), end, max<int>));
    }   
public:
    int minMaxGame(vector<int>& nums) {
        return solve(nums.begin(), prev(nums.end()), min<int>);
    }
};