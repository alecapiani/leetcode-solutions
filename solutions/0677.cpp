// 677. Map Sum Pairs
// https://leetcode.com/problems/map-sum-pairs
// 0ms solution

class MapSum {
    struct node {
        struct node *next[26] = {0};
        int sum = 0;
        int val = 0;
    } root;
    int insert_internal(string::iterator it, string::iterator end, struct node *ptr, int val) {
        if (it == end) {
            int prev = ptr->val;
            ptr->val = val;
            ptr->sum += val - prev;
            return val - prev;
        }
        int k = *it - 'a';
        if (!ptr->next[k])
            ptr->next[k] = new node();
        int v = insert_internal(next(it), end, ptr->next[k], val);
        ptr->sum += v;
        return v;
    }
public:
    void insert(string key, int val) {
        insert_internal(key.begin(), key.end(), &root, val);
    }
    
    int sum(string prefix) {
        auto ptr = &root;
        for(auto&& c: prefix) {
            int k = c-'a';
            if (!ptr->next[k])
                return 0;
            ptr = ptr->next[k];
        }
        return ptr->sum;
    }
};
