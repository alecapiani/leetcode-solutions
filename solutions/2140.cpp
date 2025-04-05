// 2140. Solving Questions With Brainpower
// https://leetcode.com/problems/solving-questions-with-brainpower
// 0ms solution

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        using ll=long long;
        vector<ll> dp(n+1);
        for(int i=0; i<n; ++i) {
            int p = questions[i][0], b = questions[i][1];
            int idx = min(i+b+1, n);
            dp[idx] = max(dp[idx], dp[i]+p);
            dp[i+1] = max(dp[i+1], dp[i]);
        }
        return dp[n];
    }
};