// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary
// 0ms solution

class Solution {
    inline static int tou(const string& str) {
        return str[0]<<16 | str[1]<<8 | str[2];
    }
    inline static string tos(const int x) {
        return string({(char)(x>>16), (char)(x>>8 & 255), (char)(x & 255)});
    }
    const int jfk = tou("JFK");

public:
    vector<string> findItinerary(const vector<vector<string>>& tickets)
    {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> adj;
        for(auto&& t: tickets)
            adj[tou(t[0])].push(tou(t[1]));

        vector<int> stops; stops.reserve(tickets.size() + 1);
        stack<int> dfs; dfs.push(jfk);
        while(!dfs.empty()) {
            int x = dfs.top();
            if (adj[x].empty()) {
                stops.push_back(x);
                dfs.pop();
                continue;
            }
            dfs.push(adj[x].top()); adj[x].pop();
        }
        vector<string> ret(stops.size());
        transform(stops.rbegin(), stops.rend(), ret.begin(), tos); // reverse
        return ret;
    }
};