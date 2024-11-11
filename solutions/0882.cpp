// 882. Reachable Nodes In Subdivided Graph
// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph

#define MN 3000
class Solution {
    bitset<MN> parsed;
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        using ii=pair<int,int>;
        using vii=vector<ii>;
        vector<vii> adj(n);
        for(auto&& e: edges) {
            int u=e[0], v=e[1], c=e[2];
            adj[u].emplace_back(v,c);
            adj[v].emplace_back(u,c);
        }
        parsed.reset();
        vector<int> dist(n, INT_MAX); dist[0] = 0;
        int ret=0;
        priority_queue<ii, vii, greater<ii>> pq;
        pq.emplace(0,0);
        while(!pq.empty()) {
            auto [du,u] = pq.top(); pq.pop();
            if (du > dist[u])
                continue;
            for(auto&& [v,cv]: adj[u]) {
                if (du + cv+1 > maxMoves)
                    ret += parsed[v] ? min(maxMoves-du, max(cv-(maxMoves-dist[v]), 0)) : maxMoves-du;
                else if (!parsed[v]) {
                    ret += cv;
                    if (du+cv+1 < dist[v])
                        pq.emplace(dist[v]=du+cv+1,v);
                }
            }
            ++ret;
            parsed.set(u, true);
        }
        return ret;
    }
};