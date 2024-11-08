// 1462. Course Schedule IV 
// https://leetcode.com/problems/course-schedule-iv
// 0ms Solution with SIMD

/*
    This is an experimental approach with SIMD and got 0ms. 
    uint128_t should be preferred for semplicity, but got 3ms.
    The difference is mainly in the bitwise OR (merge function + setbit)
    asm compiled with -O2:
        por	%xmm1, %xmm0
	    ret
    vs. with uint128_t
        movq	%rdi, %rax
        orq	%rcx, %rsi
        orq	%rdx, %rax
        movq	%rsi, %rdx
        ret
*/

#include <immintrin.h>
#pragma GCC target("sse2,sse4.1")
/* 
    sse2: _mm_setr_epi32, _mm_slli_epi64, _mm_slli_si128, _mm_or_si128, _mm_setzero_si128
    sse4.1: _mm_testz_si128
    ref https://learn.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list?view=msvc-170
*/
typedef __m128i u128;

class Solution {
public:
    // pseudo logical shift left
    static inline u128 shift(u128 bs, int x) {
        /*
            This is not a real logical shift left: since 128bit arithmetic is not supported, 64bit is used instead.
            shifting lower 64 bit and higher 64 bit as two isolated variables uint64_t,
            but this is ok since we only shift 0x1.
        */
        if (x >= 64) {
            bs = _mm_slli_si128(bs, 8); // shift left 8 byte (note: the second arguments must be an immediate)
            return _mm_slli_epi64(bs, x - 64);
        }
        return _mm_slli_epi64(bs, x);
    }

    // set bit in bs at offset x
    static inline u128 setbit(u128 bs, int x) {
        // set mask = 1 << x
        u128 mask = _mm_setr_epi32(1, 0, 0, 0);
        mask = shift(mask, x);
        // bs | mask
        return _mm_or_si128(bs, mask);
    }

    // get bit in bs at offset x
    __attribute__ ((target ("sse4.1")))
    static bool getbit(u128 bs, int x) {
        // set mask = 1 << x
        u128 mask = _mm_setr_epi32(1, 0, 0, 0);
        mask = shift(mask, x);
        // return 1 if mask & bs
        return !_mm_testz_si128(bs, mask);
    }

    // return union(dst, src)
    static inline u128 merge(u128 a, u128 b) {
        // a | b
        return _mm_or_si128(a, b);
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<u128> bs(numCourses, _mm_setzero_si128()); // bitset array
        vector<vector<int>> adj(numCourses); // adjacency list
        vector<int> inDeg(numCourses, 0); // incoming degree for each course

        // 1. Build adj list and store incoming degrees for each course
        for(auto&& p: prerequisites) {
            int u = p[0], v = p[1];
            adj[u].push_back(v); // set edge from u to v
            inDeg[v]++; // increment incoming degree of v
        }

        // 2. Push into queue each course with indeg == 0 (no prerequisites)
        // NB. a course in queue has to be processed and its prerequisites are already processed
        queue<int> q; // processing queue
        for(int i=0; i<numCourses; ++i)
            if (inDeg[i] == 0)
                q.push(i);
        
        // 3. While queue not empty
        while(!q.empty()) {
            // pop first course 'u' to process
            int u = q.front(); q.pop();

            // for each course 'v' which has 'u' as prerequisite
            for(auto& v: adj[u]) {
                // remove edge u -> v
                --inDeg[v];
                // if every prerequisite of 'v' is queued/already processed
                if (inDeg[v] == 0) 
                    q.push(v); // push 'v' into queue
                bs[v] = merge(bs[v], bs[u]); // merge the prerequisites of 'u' into 'v'
                bs[v] = setbit(bs[v], u); // set 'u' as prerequisite of 'v'
            }
        }

        // 4. Build solution
        // NB. the queries are inverted: query(u,v) if get(v,u) (if u is set as prerequisite of v)
        vector<bool> ret(queries.size());
        transform(queries.begin(), queries.end(), ret.begin(), [&bs](auto& q){
            int u = q[0], v = q[1];
            return getbit(bs[v], u);
        });
        return ret;
    }
};