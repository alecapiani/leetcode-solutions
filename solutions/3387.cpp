// 3387. Maximize Amount After Two Days of Conversions
// https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions
#include <bits/stdc++.h>
using namespace std;
class Solution {
    using data_t=pair<string,double>;
    using adj_t=unordered_map<string,vector<data_t>>;
    adj_t buildAdj(vector<vector<string>>& pairs, vector<double>& rates, int coef) {
        const int n = pairs.size();
        adj_t ret;
        for(int i=0; i<n; ++i) {
            auto u = pairs[i][0], v = pairs[i][1];
            auto w = rates[i];
            ret[u].emplace_back(v, pow(w, coef));
            ret[v].emplace_back(u, pow(w, -coef));
        }
        return ret;
    }
    unordered_map<string, double> solveAdj(adj_t& adj, string& init) {
        unordered_map<string, double> r; r[init] = 1.0;
        queue<data_t> q; q.emplace(init, 1.0);
        while(!q.empty()) {
            auto [u,w] = q.front(); q.pop();
            if (w < r[u])
                continue;
            for(auto&& [v,k] : adj[u]) {
                auto it = r.emplace(v,0).first;
                if (it->second >= k*w)
                    continue;
                q.emplace(v, it->second = k*w);
            }
        }
        return r;
    }
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        auto adj = buildAdj(pairs1, rates1, 1);
        auto m1 = solveAdj(adj, initialCurrency);
        adj = buildAdj(pairs2, rates2, -1);
        auto m2 = solveAdj(adj, initialCurrency);
        double ret = 1.0;
        for(auto&& it: m1) {
            auto jt = m2.find(it.first);
            if (jt == m2.end())
                continue;
            ret = max(ret, it.second * jt->second);
        }
        return ret;
    }
};