// 1387. Sort Integers by The Power Value
// https://leetcode.com/problems/sort-integers-by-the-power-value
// 0ms solution

#define MN 1000
static vector<int> power(MN+1, -1);
static inline int getPower(int n) {
    if (n > MN)
        return getPower(n % 2 ? 3*n+1 : n/2) + 1;
    if (power[n] >= 0)
        return power[n];
    return power[n] = getPower(n % 2 ? 3*n+1 : n/2) + 1;
}
static const auto _ = []{
    power[1] = 0;
    for(int i=2; i<=MN; ++i)
        getPower(i);
    return 'f';
}();

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> values(hi-lo+1);
        iota(values.begin(), values.end(), lo);
        nth_element(values.begin(), values.begin()+k-1, values.end(), [](int& a, int& b) {
            return power[a] == power[b] ? a < b : power[a] < power[b];
        });
        return values[k-1];
    }
};