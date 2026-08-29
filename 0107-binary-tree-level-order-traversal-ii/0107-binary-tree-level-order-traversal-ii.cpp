#include <vector>
#include <algorithm>

class Solution {
public:
    void dfs(TreeNode* node, int depth, std::vector<vector<int>>& res) {
        if (!node) return;
        
        // If this is the first time reaching this depth, create a new sub-vector
        if (depth == res.size()) {
            res.push_back(vector<int>());
        }
        
        res[depth].push_back(node->val);
        
        // Traverse left then right to maintain left-to-right order
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        dfs(root, 0, res);
        
        reverse(res.begin(), res.end());
        return res;
    }
};