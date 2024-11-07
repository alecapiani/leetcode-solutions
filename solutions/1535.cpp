// 1535. Find the Winner of an Array Game
// https://leetcode.com/problems/find-the-winner-of-an-array-game
// 0ms solution

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cnt=0, i=0, j=1;
        while(j < arr.size() && cnt < k) {
            if (arr[i] > arr[j])
                ++cnt;
            else {
                cnt=1; i=j;
            }
            ++j;
        }
        return arr[i];
    }
};