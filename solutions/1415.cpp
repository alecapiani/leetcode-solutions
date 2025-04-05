// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
// 0ms Solution

#define MN 10
static vector<vector<string>> ret(MN+1, vector<string>());
static char buff[MN+2] = {0};
static void f(int len) {
    if(len > MN)
        return;
    for(char x='a'; x<='c'; ++x)
        if (buff[len-1] != x) {
            buff[len] = x;
            ret[len].push_back(string(buff+1, len));
            f(len+1);
        }
}
static const int _ = [] {
    f(1);
    return 0;
}();
class Solution {
public:
    string getHappyString(int n, int k) {
        return k <= ret[n].size() ? ret[n][k-1] : string();
    }
};