// 2070. Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query

#define ALL(V) (V).begin(),(V).end()
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(ALL(items), [](auto& a, auto& b) {return a[0] < b[0];});
        int b = 0;
        for(auto it=items.begin(); it<items.end(); ) {
            auto jt=it;
            int m=0;
            while(jt < items.end() && (*it)[0] == (*jt)[0]) {
                m = max(m, (*jt)[1]);
                ++jt;
            }
            b = max(b, m);
            while(it < jt) {
                (*it)[1] = b;
                ++it;
            }
        }
        vector<int> ret(queries.size());
        transform(ALL(queries), ret.begin(), [&items](auto& q) {
            auto it = upper_bound(ALL(items), q, [](int x, auto& a){return a[0] > x;});
            return it > items.begin() ? (*prev(it))[1] : 0;
        });
        return ret;
    }
};