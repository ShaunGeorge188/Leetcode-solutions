#include <vector>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    
    struct Node {
        long long sum_x = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };
    
    vector<Node> tree;
    
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        // Update sum of squares first using the current sum_x
        tree[node].sum_sq = (tree[node].sum_sq + 2 * val * tree[node].sum_x % MOD + val * val % MOD * len % MOD) % MOD;
        // Update sum_x
        tree[node].sum_x = (tree[node].sum_x + val * len % MOD) % MOD;
        // Add to lazy tag
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }
    
    void push_down(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, tree[node].lazy);
            apply(2 * node + 1, mid + 1, r, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }
    
    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push_down(node, l, r);
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(2 * node, l, mid, ql, qr, val);
        if (qr > mid) update(2 * node + 1, mid + 1, r, ql, qr, val);
        
        tree[node].sum_x = (tree[2 * node].sum_x + tree[2 * node + 1].sum_x) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 1, Node());
        
        // nums[i] <= 10^5, so we can use a vector for the last occurrence
        vector<int> last_pos(100005, -1);
        long long total_sum = 0;
        
        for (int i = 0; i < n; i++) {
            int prev = last_pos[nums[i]];
            
            // Increment the distinct counts for starting positions in [prev + 1, i]
            update(1, 0, n - 1, prev + 1, i, 1);
            
            // The root of the segment tree now holds the sum of squares 
            // for all subarrays ending at current index i.
            total_sum = (total_sum + tree[1].sum_sq) % MOD;
            
            last_pos[nums[i]] = i;
        }
        
        return total_sum;
    }
};