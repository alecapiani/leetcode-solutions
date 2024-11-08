// 924. Minimize Malware Spread
// https://leetcode.com/problems/minimize-malware-spread

#define ALL(v) (v).begin(),(v).end()
class Solution {
    vector<int> parent, rank, infect;
    constexpr int find(int x) { return x == parent[x] ? x : parent[x]=find(parent[x]); }
    constexpr void join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b)
            return;
        rank[a] += rank[b];
        parent[b] = a;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        parent.resize(n); iota(ALL(parent),0);
        rank.resize(n,1);
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(graph[i][j])
                    join(i,j);
        infect.resize(n,0);
        for(auto&& i: initial)
            infect[find(i)]++;
        vector<int> inf_1;
        for(auto&& i: initial)
            if (infect[parent[i]] == 1)
                inf_1.push_back(i);
        return inf_1.empty() ? 
            *min_element(ALL(initial)) : 
            *min_element(ALL(inf_1), [this](auto& a, auto& b) { 
                return rank[parent[a]] == rank[parent[b]] ? a < b : rank[parent[a]] > rank[parent[b]]; 
            });
    }
};