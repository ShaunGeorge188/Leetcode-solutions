class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are null, structurally identical up to this point
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // One node is null and the other is not, structural mismatch
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Node values are different
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};