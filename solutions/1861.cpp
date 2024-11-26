// 1861. Rotating the Box
// https://leetcode.com/problems/rotating-the-box

#define STONE '#'
#define WALL '*'
#define EMPTY '.'
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ret(n, vector<char>(m,EMPTY));
        for(int i=0; i<m; ++i)
            for(int j=n-1, k=n-1; j>=0; --j)
                switch(box[i][j]) {
                    case STONE:
                        ret[k--][m-i-1] = STONE;
                        break;
                    case WALL:
                        ret[j][m-i-1] = WALL;
                        k=j-1;
                        break;
                }
        return ret;
    }
};