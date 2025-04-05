// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division
// 0ms solution

class Solution {
    using data_t=pair<string,double>;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<data_t>> adj;
        for(int i=0; i<equations.size(); ++i) {
            auto u = equations[i][0], v = equations[i][1];
            adj[u].emplace_back(v, values[i]);
            adj[v].emplace_back(u, 1 / values[i]);
        }

        vector<double> ret(queries.size());
        transform(queries.begin(), queries.end(), ret.begin(), [&adj](auto& q) {
            queue<data_t> qu;
            unordered_set<string> seen;
            if (adj.find(q[0]) != adj.end())
                qu.emplace(q[0], 1.0);
            while(!qu.empty()) {
                auto [v,x] = qu.front(); qu.pop();
                if (v == q[1])
                    return x;
                for(auto&& [u,y]: adj[v]) {
                    if (seen.emplace(u).second)
                        qu.emplace(u, x*y);
                }
            }
            return -1.0;
        });

        return ret;
    }
};