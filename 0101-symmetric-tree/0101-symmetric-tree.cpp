class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        // Start by comparing the immediate left and right children of the root
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Both nodes are null, structurally symmetric up to this point
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        
        // One node is null while the other exists, structural mismatch
        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }
        
        // Nodes must have identical values, and their subtrees must be exact mirrors
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right)   // Outer children
            && isMirror(t1->right, t2->left);  // Inner children
    }
};