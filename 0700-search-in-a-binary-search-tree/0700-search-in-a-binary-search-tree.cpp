class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base cases: root is null or we found the target
        if (!root || root->val == val) {
            return root;
        }
        
        // Traverse left or right depending on the value
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};