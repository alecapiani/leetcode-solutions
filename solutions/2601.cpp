// 2601. Prime Subtraction Operation
// https://leetcode.com/problems/prime-subtraction-operation/
// 0ms solution

#define MN 1000
static array<int,MN+1> e {2,2}; // e[i] = smallest p > i 
static const int sieve = []{
    int k=2;
    bitset<MN+1> bs; bs.reset();
    for(int i=3; i<=MN; i+=2)
        if (!bs[i]) {
            for(int j=i*i; j<=MN; j+=2*i)
                bs.set(j,true);
            while(k<i)
                e[k++]=i;
        }
    while(k<=MN) e[k++]=1e5;
    return 'a';
}();

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev=nums.back();
        for(auto it=nums.rbegin()+1; it != nums.rend(); ++it) {
            if (*it < prev) {
                prev = *it; continue;
            }
            prev = *it - e[*it-prev];
            if (prev <= 0)
                return false;
        }
        return true;
    }
};