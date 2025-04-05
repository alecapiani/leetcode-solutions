// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
// 0ms solution

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int curr = 0, cnt;
        int i;
        for(i=0; i<k; ++i)
            curr += blocks[i] == 'B';
        cnt = curr;
        for(;i<blocks.size(); ++i) {
            curr += (blocks[i] == 'B') - (blocks[i-k] == 'B');
            cnt = max(cnt, curr);
        }
        return k - cnt;
    }
};