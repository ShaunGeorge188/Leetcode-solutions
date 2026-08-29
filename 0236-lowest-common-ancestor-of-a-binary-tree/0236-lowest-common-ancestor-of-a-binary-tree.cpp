#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q_nodes;
        
        parent[root] = nullptr;
        q_nodes.push(root);
        
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = q_nodes.front();
            q_nodes.pop();
            
            if (node->left) {
                parent[node->left] = node;
                q_nodes.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q_nodes.push(node->right);
            }
        }
        
        unordered_set<TreeNode*> ancestors;
        
        while (p != nullptr) {
            ancestors.insert(p);
            p = parent[p];
        }
        
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }
        
        return q;
    }
};